#include "../include/validator.hpp"
#include "../include/thread_safe_queue.hpp"
#include <iostream>
#include <thread>
#include <string>

namespace signals
{
    const std::string EXIT_COMMAND = "exit";
    const std::string QUIT_COMMAND = "quit";
    const std::string STOP_SIGNAL = "stop";

    void producer_thread(queue::ThreadSafeQueue<std::string>& thread_queue)
    {
        std::string input;
        while(true)
        {
            std::cout << "Enter value (exit/quit to stop) : ";
            std::getline(std::cin, input);

            if (input == EXIT_COMMAND or input == QUIT_COMMAND)
            {
                thread_queue.Push(STOP_SIGNAL);
                break;
            }

            thread_queue.Push(input);
        }
    }

    void consumer_thread(queue::ThreadSafeQueue<std::string>& thread_queue)
    {
        processing::Validator validator;

        while(true)
        {
            const std::string value = thread_queue.Pop();

            if (value == STOP_SIGNAL)
            {
                break;
            }

            validator.Validate(value);
        }
    }
}

int main()
{
    queue::ThreadSafeQueue<std::string> thread_queue;
    
    std::thread producer(signals::producer_thread, std::ref(thread_queue));
    std::thread consumer(signals::consumer_thread, std::ref(thread_queue));

    producer.join();
    consumer.join(); // popa
}