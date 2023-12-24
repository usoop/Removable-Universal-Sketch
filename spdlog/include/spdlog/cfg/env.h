


#pragma once

#include <spdlog/cfg/helpers.h>
#include <spdlog/details/registry.h>
#include <spdlog/details/os.h>


namespace spdlog {
    namespace cfg {
        inline void load_env_levels() {
            auto env_val = details::os::getenv("SPDLOG_LEVEL");
            if (!env_val.empty()) {
                helpers::load_levels(env_val);
            }
        }

    }
}
