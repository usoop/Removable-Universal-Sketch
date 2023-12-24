


#pragma once


#if defined(SPDLOG_USE_STD_FORMAT)
#    include <format>
#elif !defined(SPDLOG_FMT_EXTERNAL)
#    if !defined(SPDLOG_COMPILED_LIB) && !defined(FMT_HEADER_ONLY)
#        define FMT_HEADER_ONLY
#    endif
#    ifndef FMT_USE_WINDOWS_H
#        define FMT_USE_WINDOWS_H 0
#    endif

#    define FMT_DEPRECATED_N_SPECIFIER

#    define FMT_DEPRECATED_OSTREAM

#    include <spdlog/fmt/bundled/core.h>
#    include <spdlog/fmt/bundled/format.h>

#else
#    include <fmt/core.h>
#    include <fmt/format.h>
#endif
