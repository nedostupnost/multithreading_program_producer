#pragma once
#include <string>

namespace processing
{
    class Validator
    {
        public:
        
        Validator() = default;

        ~Validator() = default;

        Validator(const Validator&) = delete;

        Validator& operator=(const Validator&) = delete;

        Validator(Validator&&) = delete;

        Validator& operator=(Validator&&) = delete;

        void Validate(const std::string& input) const;

        private:

        bool IsNumber(const std::string& input) const;

        bool IsThreeDigit(int value) const;
        
        bool IsDivisibleByThree(int value) const;
    };
};