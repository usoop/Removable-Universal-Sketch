


#pragma once


#if !defined(SPDLOG_USE_STD_FORMAT)
#    if !defined(SPDLOG_FMT_EXTERNAL)
#        ifdef SPDLOG_HEADER_ONLY
#            ifndef FMT_HEADER_ONLY
#                define FMT_HEADER_ONLY
#            endif
#        endif

#        include <spdlog/fmt/bundled/ostream.h>

#    else
#        include <fmt/ostream.h>
#    endif
#endif
