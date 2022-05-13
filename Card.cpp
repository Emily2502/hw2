#include "Card.h"

Card::Card(CardType type, const CardStats &stats)
{
    m_effect = type;
    m_stats = stats;
}

void Card::applyEncounter(Player &player) const
{
    if (m_effect == CardType::Battle)
    {
        //TODO:
        return;
    }
    if (m_effect == CardType::Buff)
    {
        //TODO:
        return;
    }
    if (m_effect == CardType::Heal)
    {
        //TODO:
        return;
    }
    if (m_effect == CardType::Treasure)
    {
        //TODO:
        return;
    }
}
