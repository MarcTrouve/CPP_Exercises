#pragma once

#include <string>
#include <vector>
#include "Card.hpp"
#include <random>
#include <algorithm>

class Player
{
public:
    Player(std::string name);
    static void deal_all_cards(Player &p1, Player &p2);
    Card operator[](int index);
    static inline int turn_number = 0;
    static bool play(Player p1, Player p2);
    unsigned int score() const;

private:
    std::string _name;
    std::vector<Card> _cards;
    unsigned int _score = 0;
};