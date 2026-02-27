#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>

namespace queue
{
    template <typename T>
    class ThreadSafeQueue
    {
        public:
        void Push(T value)
        {
            {
                std::lock_guard<std::mutex> lock(mutex);
                queue.push(std::move(value));
            }
            condition.notify_one();
        }
        T Pop()
        {
            std::unique_lock<std::mutex> lock(mutex);
            condition.wait(lock, [this] { return !queue.empty(); });
            T&& value = std::move(queue.front());
            queue.pop();
            return value;
        }
        bool IsEmpty() const
        {
            std::lock_guard<std::mutex> lock(mutex);
            return queue.empty();
        }

        private:
        std::queue<T> queue;
        mutable std::mutex mutex;
        std::condition_variable condition;
    };
};