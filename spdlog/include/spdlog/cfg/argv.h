


#pragma once

#include <spdlog/cfg/helpers.h>
#include <spdlog/details/registry.h>


namespace spdlog {
    namespace cfg {


        inline void load_argv_levels(int argc, const char **argv) {
            const std::string spdlog_level_prefix = "SPDLOG_LEVEL=";
            for (int i = 1; i < argc; i++) {
                std::string arg = argv[i];
                if (arg.find(spdlog_level_prefix) == 0) {
                    auto levels_string = arg.substr(spdlog_level_prefix.size());
                    helpers::load_levels(levels_string);
                }
            }
        }

        inline void load_argv_levels(int argc, char **argv) {
            load_argv_levels(argc, const_cast<const char **>(argv));
        }

    }
}
