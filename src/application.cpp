#include "../include/application.hpp"
#include <iostream>
#include <thread>

namespace app
{
    void Application::Run()
    {
        std::thread producer(&Application::ProducerTask, this);
        std::thread consumer(&Application::ConsumerTask, this);

        producer.join();
        consumer.join();
    }
    void Application::ProducerTask()
    {
        std::string input;
        while(true)
        {
            std::cout << "Enter value (exit/quit to stop): " << std::endl;
            std::getline(std::cin, input);

            if (input == EXIT_COMMAND or input == QUIT_COMMAND)
            {
                m_queue.Push(std::string(STOP_SIGNAL));
                break;
            }
            m_queue.Push(input);
        }
    }
    void Application::ConsumerTask()
    {
        processing::Validator validator;

        while(true)
        {
            const std::string value = m_queue.Pop();

            if (value == STOP_SIGNAL)
            {
                break;
            }

            processing::ValidationResult result = validator.Validate(value);
            if (result == processing::ValidationResult::NotANumber)
            {
                std::cout << "0" << std::endl;
            }
            else if (result == processing::ValidationResult::Valid)
            {
                std::cout << value << std::endl;
            }
        }
    }
}