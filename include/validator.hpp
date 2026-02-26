#pragma once
#include <string>

namespace processing
{
    class Validator
    {
        public:

        void Validate(const std::string& input) const;

        private:

        bool IsNumber(const std::string& input) const;

        bool IsThreeDigit(int value) const;
        
        bool IsDivisibleByThree(int value) const;
    };
};