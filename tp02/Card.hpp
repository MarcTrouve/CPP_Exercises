#pragma once

#include <string>
#include <iostream>

class Card
{
public:
    Card(unsigned int value, std::string color);
    void print() const;
    bool operator==(Card card) const;
    bool operator<(Card card) const;

private:
    unsigned int _value;
    std::string _color;
};