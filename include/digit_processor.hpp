#pragma once
#include <vector>

namespace digits
{
    class DigitProcessor
    {
        public:

        DigitProcessor() = default;

        ~DigitProcessor() = default;

        DigitProcessor(const DigitProcessor&) = delete;

        DigitProcessor& operator=(const DigitProcessor&) = delete;

        DigitProcessor(DigitProcessor&&) = delete;

        DigitProcessor& operator=(DigitProcessor&&) = delete;

        void Process(int numver) const;

        private:

        std::vector<int> SplitIntoDigits(int number) const;

        std::vector<int> FilterEven(const std::vector<int>& digits) const;

        void PringDigits(const std::vector<int>& digits) const;
    };
}