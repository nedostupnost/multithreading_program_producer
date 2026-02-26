#include "../include/validator.hpp"
#include <cctype>
#include <cmath>

namespace processing
{
    bool StringValidator::IsNumber(const std::string& input) const
    {
        if (input.empty())
        {
            return false;
        }

        size_t start_index = 0;

        while (start_index < input.size() && std::isspace(input[start_index]))
        {
            ++start_index;
        }

        if (start_index == input.size())
        {
            return false;
        }
        if (input[start_index] == '-' or input[start_index] == '+')
        {
            ++start_index;
        }
        if (start_index == input.size())
        {
            return false;
        }

        for (size_t i = start_index; i < input.size(); ++i)
        {
            if (!std::isdigit(input[i]))
            {
                return false;
            }
        }
        return true;

    }
    bool MathValidator::IsThreeDigit(int value) const
    {
        const int absolute_value = std::abs(value);
        return (absolute_value >= 100 and absolute_value <= 999);
    }
    bool MathValidator::IsDivisibleByThree(int value) const
    {
        return value % 3 == 0;
    }
    bool Validator::Validate(const std::string& input) const
    {
        if (!IsNumber(input))
        {
            return false;
        }

        const int value = std::stoi(input);

        if (IsThreeDigit(value) and IsDivisibleByThree(value))
        {
            return true;
        }

        return false;
    }

}