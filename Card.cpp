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

        if(m_stats.force<player.getAttackStrength())
        {
            player.levelUp();
            player.addCoins(m_stats.loot);
        }

        else
        {
            player.damage(m_stats.hpLossOnDefeat);
        }

        printBattleResult(player.isKnockOut());
        return;
    }
    if (m_effect == CardType::Buff)
    {
        //TODO:
        if(player.pay(m_stats.cost))
        {
            player.buff(m_stats.buff);
        }
        return;
    }
    if (m_effect == CardType::Heal)
    {
        //TODO:
        if(player.pay(m_stats.cost))
        {
            player.heal(m_stats.heal);
        }
        return;
    }
    if (m_effect == CardType::Treasure)
    {
        //TODO:
        player.addCoins(m_stats.loot);
        return;
    }

}

void Card::printInfo() const
{
    switch(m_effect) {
        case CardType::Battle :
            printBattleCardInfo(m_stats);
        case CardType::Heal   :
            printHealCardInfo(m_stats);
        case CardType::Buff   :
            printBuffCardInfo(m_stats);
        case  CardType::Treasure:
            printTreasureCardInfo(m_stats);
    }
    return;
}