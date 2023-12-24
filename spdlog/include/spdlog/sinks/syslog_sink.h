


#pragma once

#include <spdlog/sinks/base_sink.h>
#include <spdlog/details/null_mutex.h>
#include <spdlog/details/synchronous_factory.h>

#include <array>
#include <string>
#include <syslog.h>

namespace spdlog {
    namespace sinks {

        template<typename Mutex>
        class syslog_sink : public base_sink<Mutex> {

        public:
            syslog_sink(std::string ident, int syslog_option, int syslog_facility, bool enable_formatting)
                    : enable_formatting_{enable_formatting}, syslog_levels_{{LOG_DEBUG,
                                                                             LOG_DEBUG,
                                                                             LOG_INFO,
                                                                             LOG_WARNING,
                                                                             LOG_ERR,
                                                                             LOG_CRIT,
                                                                             LOG_INFO}}, ident_{std::move(ident)} {

                ::openlog(ident_.empty() ? nullptr : ident_.c_str(), syslog_option, syslog_facility);
            }

            ~syslog_sink() override {
                ::closelog();
            }

            syslog_sink(const syslog_sink &) = delete;

            syslog_sink &operator=(const syslog_sink &) = delete;

        protected:
            void sink_it_(const details::log_msg &msg) override {
                string_view_t payload;
                memory_buf_t formatted;
                if (enable_formatting_) {
                    base_sink<Mutex>::formatter_->format(msg, formatted);
                    payload = string_view_t(formatted.data(), formatted.size());
                } else {
                    payload = msg.payload;
                }

                size_t length = payload.size();

                if (length > static_cast<size_t>(std::numeric_limits<int>::max())) {
                    length = static_cast<size_t>(std::numeric_limits<int>::max());
                }

                ::syslog(syslog_prio_from_level(msg), "%.*s", static_cast<int>(length), payload.data());
            }

            void flush_() override {}

            bool enable_formatting_ = false;

        private:
            using levels_array = std::array<int, 7>;
            levels_array syslog_levels_;


            const std::string ident_;


            int syslog_prio_from_level(const details::log_msg &msg) const {
                return syslog_levels_.at(static_cast<levels_array::size_type>(msg.level));
            }
        };

        using syslog_sink_mt = syslog_sink<std::mutex>;
        using syslog_sink_st = syslog_sink<details::null_mutex>;
    }


    template<typename Factory = spdlog::synchronous_factory>
    inline std::shared_ptr<logger>
    syslog_logger_mt(const std::string &logger_name, const std::string &syslog_ident = "", int syslog_option = 0,
                     int syslog_facility = LOG_USER, bool enable_formatting = false) {
        return Factory::template create<sinks::syslog_sink_mt>(logger_name, syslog_ident, syslog_option,
                                                               syslog_facility, enable_formatting);
    }

    template<typename Factory = spdlog::synchronous_factory>
    inline std::shared_ptr<logger>
    syslog_logger_st(const std::string &logger_name, const std::string &syslog_ident = "", int syslog_option = 0,
                     int syslog_facility = LOG_USER, bool enable_formatting = false) {
        return Factory::template create<sinks::syslog_sink_st>(logger_name, syslog_ident, syslog_option,
                                                               syslog_facility, enable_formatting);
    }
}
