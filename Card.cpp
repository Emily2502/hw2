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
        if(m_stats.force <= player.getAttackStrength())
        {
            player.levelUp();
            player.addCoins(m_stats.loot);
            printBattleResult(true);
        }
        else
        {
            player.damage(m_stats.hpLossOnDefeat);
            printBattleResult(false);
        }
        return;
    }

    if (m_effect == CardType::Buff)
    {
        if(player.pay(m_stats.cost))
        {
            player.buff(m_stats.buff);
        }
        return;
    }

    if (m_effect == CardType::Heal)
    {
        if(player.pay(m_stats.cost))
        {
            player.heal(m_stats.heal);
        }
        return;
    }

    if (m_effect == CardType::Treasure)
    {
        player.addCoins(m_stats.loot);
        return;
    }
}

void Card::printInfo() const
{
    if (m_effect == CardType::Battle)
    {
        printBattleCardInfo(m_stats);
        return;
    }

    if (m_effect == CardType::Buff)
    {
        printBuffCardInfo(m_stats);
        return;
    }

    if (m_effect == CardType::Heal)
    {
        printHealCardInfo(m_stats);
        return;
    }

    if (m_effect == CardType::Treasure)
    {
        printTreasureCardInfo(m_stats);
        return;
    }
}