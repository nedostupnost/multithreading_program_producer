#include "../include/server_application.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

namespace app
{
    ServerApplication* ServerApplication::GetInstance(int port)
    {
        static ServerApplication instance(port);
        return &instance;
    }
    ServerApplication::ServerApplication(int port) : m_port(port) {}

    void ServerApplication::Run()
    {
        int server_fd = socket(AF_INET, SOCK_STREAM, 0);
        int opt = 1;
        setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

        sockaddr_in address;
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(m_port);

        if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0)
        {
            close(server_fd);
            return;
        }

        listen(server_fd, 3);

        while(true)
        {
            int new_socket = accept(server_fd, nullptr, nullptr);
            if (new_socket < 0) continue;

            char buffer[1024] = {0};
            ssize_t bytes_read = read(new_socket, buffer, sizeof(buffer) - 1);

            if (bytes_read > 0)
            {
                std::string received(buffer, bytes_read);

                if (received == "stop")
                {
                    close(new_socket);
                    break;
                }
                ProcessData(std::move(received));
            }
            close(new_socket);
        }
        close(server_fd);
    }
    void ServerApplication::ProcessData(std::string&& data) const
    {
        std::vector<int> digits;

        digits.reserve(data.size());

        for (char c : data)
        {
            if (std::isdigit(c))
            {
                digits.push_back(c - '0');
            }
        }
        std::sort(digits.begin(), digits.end());
        
        digits.erase(std::remove_if(digits.begin(), digits.end(), [](int d) {return d % 2 != 0; }), digits.end());
        
        for (int d : digits)
        {
            std::cout << d << " ";
        }
        std::cout << " " << std::endl;
    }   
}