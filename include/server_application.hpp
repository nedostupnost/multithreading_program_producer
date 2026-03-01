#pragma once
#include <string>

namespace app
{
    class ServerApplication
    {
        public:
        static ServerApplication* GetInstance(int port = 8080);

        ServerApplication(const ServerApplication&) = delete;
        ServerApplication& operator=(const ServerApplication&) = delete;

        void Run();

        private:
        explicit ServerApplication(int port);
        ~ServerApplication() = default;

        void ProcessData(std::string&& data) const;

        int m_port;
    };
};