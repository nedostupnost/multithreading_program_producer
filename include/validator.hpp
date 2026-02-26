#pragma once
#include <string>

namespace processing
{
    class StringValidator
    {
        public:
        StringValidator() = default;
        virtual ~StringValidator() = default;

        protected:
        bool IsNumber(const std::string& input) const;
    };
    class MathValidator
    {
        public:
        MathValidator() = default;
        virtual ~MathValidator() = default;

        protected:
        bool IsThreeDigit(int value) const;
        bool IsDivisibleByThree(int value) const;
    };
    class Validator : public StringValidator, public MathValidator
    {
        public:
        Validator() = default;
        ~Validator() override = default;
        
        bool Validate(const std::string& input) const;
    };
};