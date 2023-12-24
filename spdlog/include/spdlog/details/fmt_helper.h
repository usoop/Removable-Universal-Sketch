

#pragma once

#include <chrono>
#include <type_traits>
#include <iterator>
#include <spdlog/fmt/fmt.h>
#include <spdlog/common.h>

#ifdef SPDLOG_USE_STD_FORMAT
#    include <charconv>
#    include <limits>
#endif


namespace spdlog {
    namespace details {
        namespace fmt_helper {

            inline void append_string_view(spdlog::string_view_t view, memory_buf_t &dest) {
                auto *buf_ptr = view.data();
                dest.append(buf_ptr, buf_ptr + view.size());
            }

#ifdef SPDLOG_USE_STD_FORMAT
            template<typename T>
            inline void append_int(T n, memory_buf_t &dest)
            {

                SPDLOG_CONSTEXPR const auto BUF_SIZE = std::numeric_limits<T>::digits10 + 2;
                char buf[BUF_SIZE];

                auto [ptr, ec] = std::to_chars(buf, buf + BUF_SIZE, n, 10);
                if (ec == std::errc())
                {
                    dest.append(buf, ptr);
                }
                else
                {
                    throw_spdlog_ex("Failed to format int", static_cast<int>(ec));
                }
            }
#else

            template<typename T>
            inline void append_int(T n, memory_buf_t &dest) {
                fmt::format_int i(n);
                dest.append(i.data(), i.data() + i.size());
            }

#endif

            template<typename T>
            SPDLOG_CONSTEXPR_FUNC unsigned int count_digits_fallback(T n) {

                unsigned int count = 1;
                for (;;) {


                    if (n < 10)
                        return count;
                    if (n < 100)
                        return count + 1;
                    if (n < 1000)
                        return count + 2;
                    if (n < 10000)
                        return count + 3;
                    n /= 10000u;
                    count += 4;
                }
            }

            template<typename T>
            inline unsigned int count_digits(T n) {
                using count_type = typename std::conditional<(sizeof(T) > sizeof(uint32_t)), uint64_t, uint32_t>::type;
#ifdef SPDLOG_USE_STD_FORMAT
                return count_digits_fallback(static_cast<count_type>(n));
#else
                return static_cast<unsigned int>(fmt::


#    if FMT_VERSION < 70000
                internal
#    else
                detail
#    endif
                ::count_digits(static_cast<count_type>(n)));
#endif
            }

            inline void pad2(int n, memory_buf_t &dest) {
                if (n >= 0 && n < 100) {
                    dest.push_back(static_cast<char>('0' + n / 10));
                    dest.push_back(static_cast<char>('0' + n % 10));
                } else {
                    fmt_lib::format_to(std::back_inserter(dest), SPDLOG_FMT_STRING("{:02}"), n);
                }
            }

            template<typename T>
            inline void pad_uint(T n, unsigned int width, memory_buf_t &dest) {
                static_assert(std::is_unsigned<T>::value, "pad_uint must get unsigned T");
                for (auto digits = count_digits(n); digits < width; digits++) {
                    dest.push_back('0');
                }
                append_int(n, dest);
            }

            template<typename T>
            inline void pad3(T n, memory_buf_t &dest) {
                static_assert(std::is_unsigned<T>::value, "pad3 must get unsigned T");
                if (n < 1000) {
                    dest.push_back(static_cast<char>(n / 100 + '0'));
                    n = n % 100;
                    dest.push_back(static_cast<char>((n / 10) + '0'));
                    dest.push_back(static_cast<char>((n % 10) + '0'));
                } else {
                    append_int(n, dest);
                }
            }

            template<typename T>
            inline void pad6(T n, memory_buf_t &dest) {
                pad_uint(n, 6, dest);
            }

            template<typename T>
            inline void pad9(T n, memory_buf_t &dest) {
                pad_uint(n, 9, dest);
            }


            template<typename ToDuration>
            inline ToDuration time_fraction(log_clock::time_point tp) {
                using std::chrono::duration_cast;
                using std::chrono::seconds;
                auto duration = tp.time_since_epoch();
                auto secs = duration_cast<seconds>(duration);
                return duration_cast<ToDuration>(duration) - duration_cast<ToDuration>(secs);
            }

        }
    }
}
