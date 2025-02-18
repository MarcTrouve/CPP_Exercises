#pragma once
#include <ostream>

class PhoneNumber
{
public:
    PhoneNumber(int a, int b, int c, int d, int e)
        : _numbers { a, b, c, d, e }
    {}

    bool is_valid() const
    {
        for (auto number : _numbers)
        {
            if (number < 0 || number > 99)
            {
                return false;
            }
        }
        return true;
    }

    int operator[](int index) const
    {
        if (index < 0 || index > 4)
        {
            return -1;
        }
        return _numbers[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const PhoneNumber& phone_number);

private:
    int _numbers[5];
};

std::ostream& operator<<(std::ostream& stream, const PhoneNumber& phone_number)
{
    for (auto number : phone_number._numbers)
    {
        if (number < 10)
        {
            stream << 0 << number;
        }
        else
        {
            stream << number;
        }
    }
    return stream;
}