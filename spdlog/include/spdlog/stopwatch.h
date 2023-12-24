


#pragma once

#include <spdlog/fmt/fmt.h>
#include <chrono>


namespace spdlog {
    class stopwatch {
        using clock = std::chrono::steady_clock;
        std::chrono::time_point<clock> start_tp_;

    public:
        stopwatch()
                : start_tp_{clock::now()} {}

        std::chrono::duration<double> elapsed() const {
            return std::chrono::duration<double>(clock::now() - start_tp_);
        }

        void reset() {
            start_tp_ = clock::now();
        }
    };
}


namespace
#ifdef SPDLOG_USE_STD_FORMAT
    std
#else
fmt
#endif
{

    template<>
    struct formatter<spdlog::stopwatch> : formatter<double> {
        template<typename FormatContext>
        auto format(const spdlog::stopwatch &sw, FormatContext &ctx) -> decltype(ctx.out()) {
            return formatter<double>::format(sw.elapsed().count(), ctx);
        }
    };
}
