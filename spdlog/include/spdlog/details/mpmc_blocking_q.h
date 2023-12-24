


#pragma once


#include <spdlog/details/circular_q.h>

#include <condition_variable>
#include <mutex>

namespace spdlog {
    namespace details {

        template<typename T>
        class mpmc_blocking_queue {
        public:
            using item_type = T;

            explicit mpmc_blocking_queue(size_t max_items)
                    : q_(max_items) {}

#ifndef __MINGW32__

            void enqueue(T &&item) {
                {
                    std::unique_lock<std::mutex> lock(queue_mutex_);
                    pop_cv_.wait(lock, [this] { return !this->q_.full(); });
                    q_.push_back(std::move(item));
                }
                push_cv_.notify_one();
            }


            void enqueue_nowait(T &&item) {
                {
                    std::unique_lock<std::mutex> lock(queue_mutex_);
                    q_.push_back(std::move(item));
                }
                push_cv_.notify_one();
            }


            bool dequeue_for(T &popped_item, std::chrono::milliseconds wait_duration) {
                {
                    std::unique_lock<std::mutex> lock(queue_mutex_);
                    if (!push_cv_.wait_for(lock, wait_duration, [this] { return !this->q_.empty(); })) {
                        return false;
                    }
                    popped_item = std::move(q_.front());
                    q_.pop_front();
                }
                pop_cv_.notify_one();
                return true;
            }


            void dequeue(T &popped_item) {
                {
                    std::unique_lock<std::mutex> lock(queue_mutex_);
                    push_cv_.wait(lock, [this] { return !this->q_.empty(); });
                    popped_item = std::move(q_.front());
                    q_.pop_front();
                }
                pop_cv_.notify_one();
            }

#else




            void enqueue(T &&item)
            {
                std::unique_lock<std::mutex> lock(queue_mutex_);
                pop_cv_.wait(lock, [this] { return !this->q_.full(); });
                q_.push_back(std::move(item));
                push_cv_.notify_one();
            }


            void enqueue_nowait(T &&item)
            {
                std::unique_lock<std::mutex> lock(queue_mutex_);
                q_.push_back(std::move(item));
                push_cv_.notify_one();
            }



            bool dequeue_for(T &popped_item, std::chrono::milliseconds wait_duration)
            {
                std::unique_lock<std::mutex> lock(queue_mutex_);
                if (!push_cv_.wait_for(lock, wait_duration, [this] { return !this->q_.empty(); }))
                {
                    return false;
                }
                popped_item = std::move(q_.front());
                q_.pop_front();
                pop_cv_.notify_one();
                return true;
            }


            void dequeue(T &popped_item)
            {
                std::unique_lock<std::mutex> lock(queue_mutex_);
                push_cv_.wait(lock, [this] { return !this->q_.empty(); });
                popped_item = std::move(q_.front());
                q_.pop_front();
                pop_cv_.notify_one();
            }

#endif

            size_t overrun_counter() {
                std::unique_lock<std::mutex> lock(queue_mutex_);
                return q_.overrun_counter();
            }

            size_t size() {
                std::unique_lock<std::mutex> lock(queue_mutex_);
                return q_.size();
            }

            void reset_overrun_counter() {
                std::unique_lock<std::mutex> lock(queue_mutex_);
                q_.reset_overrun_counter();
            }

        private:
            std::mutex queue_mutex_;
            std::condition_variable push_cv_;
            std::condition_variable pop_cv_;
            spdlog::details::circular_q<T> q_;
        };
    }
}
