#include "../include/validator.hpp"
#include <iostream>
#include <string>

namespace processing
{
    void Validator::Validate(const std::string& input) const
    {
        if (!IsNumber(input))
        {
            std::cout << "is number" << std::endl;
            return;
        }

        const int value = std::stoi(input);

        if (IsThreeDigit(value) and IsDivisibleByThree(value))
        {
            std::cout << "Number " << value << " passed validation" << std::endl; 
        }
    }

    bool Validator::IsNumber(const std::string& input ) const
    {
        if (input.empty())
        {
            return false;
        }

        const int start_index = (input[0] == '-') ? 1 : 0;

        if (start_index == input.size())
        {
            return false;
        }

        for (int i = start_index; i < input.size(); ++i)
        {
            if (!std::isdigit(input[i]))
            {
                return false;
            }
        }

        return true;
    }

    bool Validator::IsThreeDigit(int value) const
    {
        const int absolute_value = (value < 0) ? -value : value;

        return (absolute_value >= 100 and absolute_value <= 999);
    }

    bool Validator::IsDivisibleByThree(int value) const
    {
        return value % 3 == 0;
    }

};
