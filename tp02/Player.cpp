#include "Player.hpp"

Player::Player(std::string name) : _name{name}
{
}

void Player::deal_all_cards(Player &p1, Player &p2)
{
    std::vector<Card> all_cards;
    for (int i = 7; i < 14; i++)
    {
        std::string color;
        for (int j = 0; j < 4; j++)
        {
            switch (j)
            {
            case 0:
                color = "pique";
                break;

            case 1:
                color = "carreau";
                break;

            case 2:
                color = "trefle";
                break;

            case 3:
                color = "coeur";
                break;
            default:
                break;
            }
            all_cards.emplace_back(Card(i, color));
        }
    }

    std::random_device rd;
    std::shuffle(all_cards.begin(), all_cards.end(), std::default_random_engine(rd()));
    for (int i = 0; i < all_cards.size() / 2; i++)
    {
        p1._cards.emplace_back(all_cards.at(i));
    }
    for (int i = all_cards.size() / 2; i < all_cards.size(); i++)
    {
        p2._cards.emplace_back(all_cards.at(i));
    }
}

Card Player::operator[](int index)
{
    return _cards.at(index);
}

bool Player::play(Player p1, Player p2)
{
    if (p1._cards.size() == 0 || p2._cards.size() == 0)
    {
        return true;
    }
    Card p1_card = p1._cards.at(Player::turn_number);
    Card p2_card = p2._cards.at(Player::turn_number);
    std::cout << p1._name << " joue : ";
    p1_card.print();
    std::cout << p2._name << " joue :";
    p2_card.print();
    if (p1_card < p2_card)
    {
        p2._score += 1;
    }
    return false;
}

unsigned int Player::score() const
{
    return _score;
}