#pragma once

#include "PhoneNumber.hpp"

#include <string>

class PhoneBookEntry
{
public:
    PhoneBookEntry(std::string name, PhoneNumber pn)
        : _name { name }
        , _pn { pn }
    {}

    const std::string& get_name() const { return _name; }

    const PhoneNumber& get_number() const { return _pn; }

    bool operator==(const PhoneBookEntry& entry) const { return entry.get_name() == _name; }

private:
    std::string _name;
    PhoneNumber _pn;
};