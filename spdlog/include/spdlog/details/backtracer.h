


#pragma once

#include <spdlog/details/log_msg_buffer.h>
#include <spdlog/details/circular_q.h>

#include <atomic>
#include <mutex>
#include <functional>


namespace spdlog {
    namespace details {
        class SPDLOG_API backtracer
                {
                        mutable std::mutex mutex_;
                        std::atomic<bool> enabled_{ false };
                        circular_q<log_msg_buffer> messages_;

                        public:
                        backtracer() = default;
                        backtracer(const backtracer &other);

                        backtracer(backtracer &&other) SPDLOG_NOEXCEPT;
                        backtracer &operator=(backtracer other);

                        void enable(size_t size);
                        void disable();
                        bool enabled() const;
                        void push_back(const log_msg &msg);
                        bool empty() const;


                        void foreach_pop(std::function<void(const details::log_msg &)> fun);
                };

    }
}

#ifdef SPDLOG_HEADER_ONLY
#    include "backtracer-inl.h"
#endif
