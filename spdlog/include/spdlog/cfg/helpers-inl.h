


#pragma once

#ifndef SPDLOG_HEADER_ONLY

#    include <spdlog/cfg/helpers.h>

#endif

#include <spdlog/spdlog.h>
#include <spdlog/details/os.h>
#include <spdlog/details/registry.h>

#include <algorithm>
#include <string>
#include <utility>
#include <sstream>

namespace spdlog {
    namespace cfg {
        namespace helpers {


            inline std::string &to_lower_(std::string &str) {
                std::transform(
                        str.begin(), str.end(), str.begin(),
                        [](char ch) { return static_cast<char>((ch >= 'A' && ch <= 'Z') ? ch + ('a' - 'A') : ch); });
                return str;
            }


            inline std::string &trim_(std::string &str) {
                const char *spaces = " \n\r\t";
                str.erase(str.find_last_not_of(spaces) + 1);
                str.erase(0, str.find_first_not_of(spaces));
                return str;
            }


            inline std::pair<std::string, std::string> extract_kv_(char sep, const std::string &str) {
                auto n = str.find(sep);
                std::string k, v;
                if (n == std::string::npos) {
                    v = str;
                } else {
                    k = str.substr(0, n);
                    v = str.substr(n + 1);
                }
                return std::make_pair(trim_(k), trim_(v));
            }


            inline std::unordered_map<std::string, std::string> extract_key_vals_(const std::string &str) {
                std::string token;
                std::istringstream token_stream(str);
                std::unordered_map<std::string, std::string> rv{};
                while (std::getline(token_stream, token, ',')) {
                    if (token.empty()) {
                        continue;
                    }
                    auto kv = extract_kv_('=', token);
                    rv[kv.first] = kv.second;
                }
                return rv;
            }

            SPDLOG_INLINE void load_levels(const std::string &input) {
                if (input.empty() || input.size() > 512) {
                    return;
                }

                auto key_vals = extract_key_vals_(input);
                std::unordered_map<std::string, level::level_enum> levels;
                level::level_enum global_level = level::info;
                bool global_level_found = false;

                for (auto &name_level: key_vals) {
                    auto &logger_name = name_level.first;
                    auto level_name = to_lower_(name_level.second);
                    auto level = level::from_str(level_name);

                    if (level == level::off && level_name != "off") {
                        continue;
                    }
                    if (logger_name.empty()) {
                        global_level_found = true;
                        global_level = level;
                    } else {
                        levels[logger_name] = level;
                    }
                }

                details::registry::instance().set_levels(std::move(levels),
                                                         global_level_found ? &global_level : nullptr);
            }

        }
    }
}
