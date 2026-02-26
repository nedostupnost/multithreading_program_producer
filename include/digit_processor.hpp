#pragma once
#include <vector>

namespace digits
{
    class DigitProcessor
    {
        public:

        void Process(int number) const;

        private:

        std::vector<int> SplitIntoDigits(int number) const;

        std::vector<int> FilterEven(const std::vector<int>& digits) const;

        void PringDigits(const std::vector<int>& digits) const;
    };
}