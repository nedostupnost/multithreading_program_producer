#pragma once
#include "thread_safe_queue.hpp"
#include "validator.hpp"
#include <string>
#include <string_view>
#include <mutex>

namespace app
{
    class ClientApplication
    {
        public:
        static ClientApplication* GetInstance(const std::string& server_ip = "127.0.0.1", int server_port = 8080);
        
        ClientApplication(const ClientApplication&) = delete;
        ClientApplication& operator=(const ClientApplication&) = delete;

        void Run();

        private:
        ClientApplication(const std::string& server_ip, int server_port);
        ~ClientApplication() = default;

        void ProducerTask();
        void ConsumerTask();
        void SendToServer(const std::string& data) const;

        queue::ThreadSafeQueue<std::string> m_queue;
        std::string m_server_ip;
        int m_server_port;

        static constexpr std::string_view EXIT_COMMAND = "exit";
        static constexpr std::string_view QUIT_COMMAND = "quit";
        static constexpr std::string_view STOP_SIGNAL = "stop";
    };
};