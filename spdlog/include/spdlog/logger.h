


#pragma once


#include <spdlog/common.h>
#include <spdlog/details/log_msg.h>
#include <spdlog/details/backtracer.h>

#ifdef SPDLOG_WCHAR_TO_UTF8_SUPPORT
#    ifndef _WIN32
#        error SPDLOG_WCHAR_TO_UTF8_SUPPORT only supported on windows
#    endif
#    include <spdlog/details/os.h>
#endif

#include <vector>

#ifndef SPDLOG_NO_EXCEPTIONS
#    define SPDLOG_LOGGER_CATCH(location)                                                                                                  \
        catch (const std::exception &ex)                                                                                                   \
        {                                                                                                                                  \
            if (location.filename)                                                                                                         \
            {                                                                                                                              \
                err_handler_(fmt_lib::format(SPDLOG_FMT_STRING("{} [{}({})]"), ex.what(), location.filename, location.line));              \
            }                                                                                                                              \
            else                                                                                                                           \
            {                                                                                                                              \
                err_handler_(ex.what());                                                                                                   \
            }                                                                                                                              \
        }                                                                                                                                  \
        catch (...)                                                                                                                        \
        {                                                                                                                                  \
            err_handler_("Rethrowing unknown exception in logger");                                                                        \
            throw;                                                                                                                         \
        }
#else
#    define SPDLOG_LOGGER_CATCH(location)
#endif

namespace spdlog {

    class SPDLOG_API logger
            {
                    public:

                    explicit logger(std::string name)
                    : name_(std::move(name))
                    , sinks_()
                    {}


                    template<typename It>
                    logger(std::string name, It begin, It end)
                    : name_(std::move(name))
                    , sinks_(begin, end)
                    {}


                    logger(std::string name, sink_ptr single_sink)
                    : logger(std::move(name), { std::move(single_sink) })
                    {}


                    logger(std::string name, sinks_init_list sinks)
                    : logger(std::move(name), sinks.begin(), sinks.end())
                    {}

                    virtual ~logger() = default;

                    logger(const logger &other);
                    logger(logger &&other) SPDLOG_NOEXCEPT;
                    logger &operator=(logger other) SPDLOG_NOEXCEPT;
                    void swap(spdlog::logger &other) SPDLOG_NOEXCEPT;

                    template<typename... Args>
                    void log(source_loc loc, level::level_enum lvl, format_string_t<Args...> fmt, Args &&... args)
                    {
                        log_(loc, lvl, details::to_string_view(fmt), std::forward<Args>(args)...);
                    }

                    template<typename... Args>
                    void log(level::level_enum lvl, format_string_t<Args...> fmt, Args &&... args)
                    {
                        log(source_loc{}, lvl, fmt, std::forward<Args>(args)...);
                    }

                    template<typename T>
                    void log(level::level_enum lvl, const T &msg)
                    {
                        log(source_loc{}, lvl, msg);
                    }


                    template<class T, typename std::enable_if<!is_convertible_to_any_format_string<const T &>::value, int>::type = 0>
                    void log(source_loc loc, level::level_enum lvl, const T &msg)
                    {
                        log(loc, lvl, "{}", msg);
                    }

                    void log(log_clock::time_point log_time, source_loc loc, level::level_enum lvl, string_view_t msg)
                    {
                        bool log_enabled = should_log(lvl);
                        bool traceback_enabled = tracer_.enabled();
                        if (!log_enabled && !traceback_enabled) {
                            return;
                        }

                        details::log_msg log_msg(log_time, loc, name_, lvl, msg);
                        log_it_(log_msg, log_enabled, traceback_enabled);
                    }

                    void log(source_loc loc, level::level_enum lvl, string_view_t msg)
                    {
                        bool log_enabled = should_log(lvl);
                        bool traceback_enabled = tracer_.enabled();
                        if (!log_enabled && !traceback_enabled) {
                            return;
                        }

                        details::log_msg log_msg(loc, name_, lvl, msg);
                        log_it_(log_msg, log_enabled, traceback_enabled);
                    }

                    void log(level::level_enum lvl, string_view_t msg)
                    {
                        log(source_loc{}, lvl, msg);
                    }

                    template<typename... Args>
                    void trace(format_string_t<Args...> fmt, Args &&... args)
                    {
                        log(level::trace, fmt, std::forward<Args>(args)...);
                    }

                    template<typename... Args>
                    void debug(format_string_t<Args...> fmt, Args &&... args)
                    {
                        log(level::debug, fmt, std::forward<Args>(args)...);
                    }

                    template<typename... Args>
                    void info(format_string_t<Args...> fmt, Args &&... args)
                    {
                        log(level::info, fmt, std::forward<Args>(args)...);
                    }

                    template<typename... Args>
                    void warn(format_string_t<Args...> fmt, Args &&... args)
                    {
                        log(level::warn, fmt, std::forward<Args>(args)...);
                    }

                    template<typename... Args>
                    void error(format_string_t<Args...> fmt, Args &&... args)
                    {
                        log(level::err, fmt, std::forward<Args>(args)...);
                    }

                    template<typename... Args>
                    void critical(format_string_t<Args...> fmt, Args &&... args)
                    {
                        log(level::critical, fmt, std::forward<Args>(args)...);
                    }

#ifdef SPDLOG_WCHAR_TO_UTF8_SUPPORT
                    template<typename... Args>
                    void log(source_loc loc, level::level_enum lvl, wformat_string_t<Args...> fmt, Args &&... args)
                    {
                        log_(loc, lvl, details::to_string_view(fmt), std::forward<Args>(args)...);
                    }

                    template<typename... Args>
                    void log(level::level_enum lvl, wformat_string_t<Args...> fmt, Args &&... args)
                    {
                        log(source_loc{}, lvl, fmt, std::forward<Args>(args)...);
                    }

                    void log(log_clock::time_point log_time, source_loc loc, level::level_enum lvl, wstring_view_t msg)
                    {
                        bool log_enabled = should_log(lvl);
                        bool traceback_enabled = tracer_.enabled();
                        if (!log_enabled && !traceback_enabled)
                        {
                            return;
                        }

                        memory_buf_t buf;
                        details::os::wstr_to_utf8buf(wstring_view_t(msg.data(), msg.size()), buf);
                        details::log_msg log_msg(log_time, loc, name_, lvl, string_view_t(buf.data(), buf.size()));
                        log_it_(log_msg, log_enabled, traceback_enabled);
                    }

                    void log(source_loc loc, level::level_enum lvl, wstring_view_t msg)
                    {
                        bool log_enabled = should_log(lvl);
                        bool traceback_enabled = tracer_.enabled();
                        if (!log_enabled && !traceback_enabled)
                        {
                            return;
                        }

                        memory_buf_t buf;
                        details::os::wstr_to_utf8buf(wstring_view_t(msg.data(), msg.size()), buf);
                        details::log_msg log_msg(loc, name_, lvl, string_view_t(buf.data(), buf.size()));
                        log_it_(log_msg, log_enabled, traceback_enabled);
                    }

                    void log(level::level_enum lvl, wstring_view_t msg)
                    {
                        log(source_loc{}, lvl, msg);
                    }

                    template<typename... Args>
                    void trace(wformat_string_t<Args...> fmt, Args &&... args)
                    {
                        log(level::trace, fmt, std::forward<Args>(args)...);
                    }

                    template<typename... Args>
                    void debug(wformat_string_t<Args...> fmt, Args &&... args)
                    {
                        log(level::debug, fmt, std::forward<Args>(args)...);
                    }

                    template<typename... Args>
                    void info(wformat_string_t<Args...> fmt, Args &&... args)
                    {
                        log(level::info, fmt, std::forward<Args>(args)...);
                    }

                    template<typename... Args>
                    void warn(wformat_string_t<Args...> fmt, Args &&... args)
                    {
                        log(level::warn, fmt, std::forward<Args>(args)...);
                    }

                    template<typename... Args>
                    void error(wformat_string_t<Args...> fmt, Args &&... args)
                    {
                        log(level::err, fmt, std::forward<Args>(args)...);
                    }

                    template<typename... Args>
                    void critical(wformat_string_t<Args...> fmt, Args &&... args)
                    {
                        log(level::critical, fmt, std::forward<Args>(args)...);
                    }
#endif

                    template<typename T>
                    void trace(const T &msg)
                    {
                        log(level::trace, msg);
                    }

                    template<typename T>
                    void debug(const T &msg)
                    {
                        log(level::debug, msg);
                    }

                    template<typename T>
                    void info(const T &msg)
                    {
                        log(level::info, msg);
                    }

                    template<typename T>
                    void warn(const T &msg)
                    {
                        log(level::warn, msg);
                    }

                    template<typename T>
                    void error(const T &msg)
                    {
                        log(level::err, msg);
                    }

                    template<typename T>
                    void critical(const T &msg)
                    {
                        log(level::critical, msg);
                    }


                    bool should_log(level::level_enum msg_level) const
                    {
                        return msg_level >= level_.load(std::memory_order_relaxed);
                    }


                    bool should_backtrace() const
                    {
                        return tracer_.enabled();
                    }

                    void set_level(level::level_enum log_level);

                    level::level_enum level() const;

                    const std::string &name() const;



                    void set_formatter(std::unique_ptr<formatter> f);





                    void set_pattern(std::string pattern, pattern_time_type time_type = pattern_time_type::local);



                    void enable_backtrace(size_t n_messages);
                    void disable_backtrace();
                    void dump_backtrace();


                    void flush();
                    void flush_on(level::level_enum log_level);
                    level::level_enum flush_level() const;


                    const std::vector<sink_ptr> &sinks() const;

                    std::vector<sink_ptr> &sinks();


                    void set_error_handler(err_handler);


                    virtual std::shared_ptr<logger> clone(std::string logger_name);

                    protected:
                    std::string name_;
                    std::vector<sink_ptr> sinks_;
                    spdlog::level_t level_{ level::info };
                    spdlog::level_t flush_level_{ level::off };
                    err_handler custom_err_handler_{ nullptr };
                    details::backtracer tracer_;


                    template<typename... Args>
                    void log_(source_loc loc, level::level_enum lvl, string_view_t fmt, Args &&... args)
                    {
                        bool log_enabled = should_log(lvl);
                        bool traceback_enabled = tracer_.enabled();
                        if (!log_enabled && !traceback_enabled) {
                            return;
                        }
                        SPDLOG_TRY
                        {
                            memory_buf_t buf;
#ifdef SPDLOG_USE_STD_FORMAT
                            fmt_lib::vformat_to(std::back_inserter(buf), fmt, fmt_lib::make_format_args(std::forward<Args>(args)...));
#else
                            fmt::vformat_to(fmt::appender(buf), fmt,
                                            fmt::make_format_args(std::forward<Args>(args)...));
#endif

                            details::log_msg log_msg(loc, name_, lvl, string_view_t(buf.data(), buf.size()));
                            log_it_(log_msg, log_enabled, traceback_enabled);
                        }
                        SPDLOG_LOGGER_CATCH(loc)
                    }

#ifdef SPDLOG_WCHAR_TO_UTF8_SUPPORT
                    template<typename... Args>
                    void log_(source_loc loc, level::level_enum lvl, wstring_view_t fmt, Args &&... args)
                    {
                        bool log_enabled = should_log(lvl);
                        bool traceback_enabled = tracer_.enabled();
                        if (!log_enabled && !traceback_enabled)
                        {
                            return;
                        }
                        SPDLOG_TRY
                        {

                            wmemory_buf_t wbuf;
                            fmt_lib::vformat_to(
                                std::back_inserter(wbuf), fmt, fmt_lib::make_format_args<fmt_lib::wformat_context>(std::forward<Args>(args)...));

                            memory_buf_t buf;
                            details::os::wstr_to_utf8buf(wstring_view_t(wbuf.data(), wbuf.size()), buf);
                            details::log_msg log_msg(loc, name_, lvl, string_view_t(buf.data(), buf.size()));
                            log_it_(log_msg, log_enabled, traceback_enabled);
                        }
                        SPDLOG_LOGGER_CATCH(loc)
                    }
#endif


                    void log_it_(const details::log_msg &log_msg, bool log_enabled, bool traceback_enabled);
                    virtual void sink_it_(const details::log_msg &msg);
                    virtual void flush_();
                    void dump_backtrace_();
                    bool should_flush_(const details::log_msg &msg);



                    void err_handler_(const std::string &msg);
            };

    void swap(logger & a, logger & b);

}

#ifdef SPDLOG_HEADER_ONLY
#    include "logger-inl.h"
#endif
