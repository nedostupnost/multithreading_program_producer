#pragma once
#include <string>
#include <memory>

namespace processing
{
    enum class ValidationResult
    {
        NotANumber,
        InvalidMath,
        Valid
    };
    class Validator
    {
        public:
        virtual ~Validator() = default;
        virtual ValidationResult Validate(const std::string& input) const = 0;
    };    
    class StringValidator : public Validator
    {
        public:
        ValidationResult Validate(const std::string& input) const override;

        private:
        bool IsNumber(const std::string& input) const;
    };
    class MathValidator : public Validator
    {
        public:
        ValidationResult Validate(const std::string& input) const override;
        
        private:
        bool IsThreeDigit(int value) const;
        bool IsDivisibleByThree(int value) const;
    };

    class PrimaryValidator : public Validator
    {
        public:
        PrimaryValidator();
        ValidationResult Validate(const std::string& input) const override;

        private:
        std::unique_ptr<Validator> m_string_validator;
        std::unique_ptr<Validator> m_math_validator;
    };
};