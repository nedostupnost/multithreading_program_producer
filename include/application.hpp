#pragma once
#include "thread_safe_queue.hpp"
#include "validator.hpp"
#include <string>
#include <string_view>
#include <mutex>

namespace app
{
    class Application
    {
        public:
        void Run();

        private:
        void ProducerTask();
        void ConsumerTask();

        queue::ThreadSafeQueue<std::string> m_queue;

        static constexpr std::string_view EXIT_COMMAND = "exit";
        static constexpr std::string_view QUIT_COMMAND = "quit";
        static constexpr std::string_view STOP_SIGNAL = "stop";
    };
};