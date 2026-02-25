#pragma once
#include <string>

namespace socket_connection
{
    constexpr int PORT = 8080;
    const std::string HOST = "127.0.0.1";
    const std::string STOP_SIGNAL = "__stop__";

    class Server
    {
        public:

        Server();

        ~Server();

        Server(const Server&) = delete;

        Server& operator=(const Server&) = delete;

        Server(Server&&) = delete;

        Server& operator=(Server&&) = delete;

        void AcceptConnection();

        std::string recive() const;
        
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