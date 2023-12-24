


#pragma once

#include <spdlog/common.h>
#include <tuple>

namespace spdlog {
    namespace details {


        class SPDLOG_API file_helper
                {
                        public:
                        file_helper() = default;
                        explicit file_helper(const file_event_handlers &event_handlers);

                        file_helper(const file_helper &) = delete;
                        file_helper &operator=(const file_helper &) = delete;
                        ~file_helper();

                        void open(const filename_t &fname, bool truncate = false);
                        void reopen(bool truncate);
                        void flush();
                        void sync();
                        void close();
                        void write(const memory_buf_t &buf);
                        size_t size() const;
                        const filename_t &filename() const;














                        static std::tuple<filename_t, filename_t> split_by_extension(const filename_t &fname);

                        private:
                        const int open_tries_ = 5;
                        const unsigned int open_interval_ = 10;
                        std::FILE *fd_{ nullptr };
                        filename_t filename_;
                        file_event_handlers event_handlers_;
                };
    }
}

#ifdef SPDLOG_HEADER_ONLY
#    include "file_helper-inl.h"
#endif
