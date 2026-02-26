#pragma once
#include <string>

namespace socket_connection
{
    inline constexpr int PORT = 8080;
    inline const std::string HOST = "127.0.0.1";
    inline const std::string STOP_SIGNAL = "__stop__";

    class Server
    {
        public:

        void AcceptConnection();

        std::string receive() const;
        
        void close();

        private:

        int server_id;

        int client_id;
    };

    class Client
    {
        public:
        
        Client();
        
        ~Client();

        Client(const Client&) = delete;
        
        Client& operator=(const Client&) = delete;

        Client(Client&&) = delete;

        Client& operator=(Client&&) = delete;

        void send(const std::string& message) const;

        void close();

        private:
        
        int socket_fd;

    };
}