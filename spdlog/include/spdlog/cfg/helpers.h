


#pragma once

#include <spdlog/common.h>
#include <unordered_map>

namespace spdlog {
    namespace cfg {
        namespace helpers {


            SPDLOG_API void load_levels(const std::string &txt);
        }

    }
}

#ifdef SPDLOG_HEADER_ONLY
#    include "helpers-inl.h"
#endif
