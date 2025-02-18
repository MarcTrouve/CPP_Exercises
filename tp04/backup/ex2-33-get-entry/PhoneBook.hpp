#pragma once

#include "PhoneBookEntry.hpp"

#include <string>
#include <vector>

class PhoneBook
{
public:
    PhoneBook() {}
    bool add_entry(const PhoneBookEntry& entry)
    {
        if (!entry.get_number().is_valid() || get_number(entry.get_name()) != nullptr)
        {
            return false;
        }
        _book.emplace_back(entry);
        return true;
    }
    const PhoneNumber* get_number(const std::string& name) const
    {
        for (auto& entry : _book)
        {
            if (entry.get_name() == name)
            {
                return &entry.get_number();
            }
        }
        return nullptr;
    }

private:
    std::vector<PhoneBookEntry> _book;
};