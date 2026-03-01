#include "../include/client_application.hpp"
#include <iostream>
#include <thread>
#include <memory>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

namespace app
{
    ClientApplication* ClientApplication::GetInstance(const std::string& server_ip, int server_port)
    {
        static ClientApplication instance(server_ip, server_port);
        return &instance;
    }
    ClientApplication::ClientApplication(const std::string& server_ip, int server_port)
    : m_server_ip(server_ip), m_server_port(server_port) {}
    void ClientApplication::Run()
    {
        std::thread producer(&ClientApplication::ProducerTask, this);
        std::thread consumer(&ClientApplication::ConsumerTask, this);

        producer.join();
        consumer.join();
    }
    void ClientApplication::ProducerTask()
    {
        std::string input;
        while (true)
        {
            std::cout << "Enter valie (exit/quit to stop): " << std::endl;
            std::getline(std::cin, input);

            if (input == EXIT_COMMAND or input == QUIT_COMMAND)
            {
                m_queue.Push(std::string(STOP_SIGNAL));
                break;
            }
            m_queue.Push(std::move(input));
        }
    }
    void ClientApplication::ConsumerTask()
    {
        std::unique_ptr<processing::Validator> validator = std::make_unique<processing::PrimaryValidator>();

        while(true)
        {
            std::string value = m_queue.Pop();

            if (value == STOP_SIGNAL)
            {
                SendToServer(std::string(STOP_SIGNAL));
                break;
            }
            processing::ValidationResult result = validator->Validate(value);

            if (result == processing::ValidationResult::NotANumber)
            {
                std::cout << "0" << std::endl;
            }
            else if (result == processing::ValidationResult::Valid)
            {
                std::cout << value << std::endl;
                SendToServer(value);
            }
        }
    }
    void ClientApplication::SendToServer(const std::string& data) const
    {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in serv_addr;
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(m_server_port);
        inet_pton(AF_INET, m_server_ip.c_str(), &serv_addr.sin_addr);

        if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == 0)
        {
            ssize_t sent = send(sock, data.c_str(), data.length(), 0);
        }
        close(sock);
    }
}