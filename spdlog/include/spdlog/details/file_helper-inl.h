


#pragma once

#ifndef SPDLOG_HEADER_ONLY

#    include <spdlog/details/file_helper.h>

#endif

#include <spdlog/details/os.h>
#include <spdlog/common.h>

#include <cerrno>
#include <chrono>
#include <cstdio>
#include <string>
#include <thread>
#include <tuple>

namespace spdlog {
    namespace details {

        SPDLOG_INLINE file_helper::file_helper(const file_event_handlers &event_handlers)
                : event_handlers_(event_handlers) {}

        SPDLOG_INLINE file_helper::~file_helper() {
            close();
        }

        SPDLOG_INLINE void file_helper::open(const filename_t &fname, bool truncate) {
            close();
            filename_ = fname;

            auto *mode = SPDLOG_FILENAME_T("ab");
            auto *trunc_mode = SPDLOG_FILENAME_T("wb");

            if (event_handlers_.before_open) {
                event_handlers_.before_open(filename_);
            }
            for (int tries = 0; tries < open_tries_; ++tries) {

                os::create_dir(os::dir_name(fname));
                if (truncate) {


                    std::FILE *tmp;
                    if (os::fopen_s(&tmp, fname, trunc_mode)) {
                        continue;
                    }
                    std::fclose(tmp);
                }
                if (!os::fopen_s(&fd_, fname, mode)) {
                    if (event_handlers_.after_open) {
                        event_handlers_.after_open(filename_, fd_);
                    }
                    return;
                }

                details::os::sleep_for_millis(open_interval_);
            }

            throw_spdlog_ex("Failed opening file " + os::filename_to_str(filename_) + " for writing", errno);
        }

        SPDLOG_INLINE void file_helper::reopen(bool truncate) {
            if (filename_.empty()) {
                throw_spdlog_ex("Failed re opening file - was not opened before");
            }
            this->open(filename_, truncate);
        }

        SPDLOG_INLINE void file_helper::flush() {
            if (std::fflush(fd_) != 0) {
                throw_spdlog_ex("Failed flush to file " + os::filename_to_str(filename_), errno);
            }
        }

        SPDLOG_INLINE void file_helper::sync() {
            if (!os::fsync(fd_)) {
                throw_spdlog_ex("Failed to fsync file " + os::filename_to_str(filename_), errno);
            }
        }

        SPDLOG_INLINE void file_helper::close() {
            if (fd_ != nullptr) {
                if (event_handlers_.before_close) {
                    event_handlers_.before_close(filename_, fd_);
                }

                std::fclose(fd_);
                fd_ = nullptr;

                if (event_handlers_.after_close) {
                    event_handlers_.after_close(filename_);
                }
            }
        }

        SPDLOG_INLINE void file_helper::write(const memory_buf_t &buf) {
            size_t msg_size = buf.size();
            auto data = buf.data();
            if (std::fwrite(data, 1, msg_size, fd_) != msg_size) {
                throw_spdlog_ex("Failed writing to file " + os::filename_to_str(filename_), errno);
            }
        }

        SPDLOG_INLINE size_t

        file_helper::size() const {
            if (fd_ == nullptr) {
                throw_spdlog_ex("Cannot use size() on closed file " + os::filename_to_str(filename_));
            }
            return os::filesize(fd_);
        }

        SPDLOG_INLINE const filename_t
        &

        file_helper::filename() const {
            return filename_;
        }


        SPDLOG_INLINE std::tuple<filename_t, filename_t>

        file_helper::split_by_extension(const filename_t &fname) {
            auto ext_index = fname.rfind('.');


            if (ext_index == filename_t::npos || ext_index == 0 || ext_index == fname.size() - 1) {
                return std::make_tuple(fname, filename_t());
            }


            auto folder_index = fname.find_last_of(details::os::folder_seps_filename);
            if (folder_index != filename_t::npos && folder_index >= ext_index - 1) {
                return std::make_tuple(fname, filename_t());
            }


            return std::make_tuple(fname.substr(0, ext_index), fname.substr(ext_index));
        }

    }
}
