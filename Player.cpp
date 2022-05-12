#include "Player.h"
#include <iostream>
#define INITIAL_LEVEL 1
#define INITIAL_COINS 0
#define MAX_LEVEL 10

Player::Player(const char* name, int maxHp, int force)
{
    m_name = name;
    m_level = INITIAL_LEVEL;
    m_coins = INITIAL_COINS;
    m_force = force;
    m_maxHp = maxHp;
    m_hp = m_maxHp;
}

Player::~Player()
{
    delete m_name;
}

void Player::printPlayerInfo()
{
    std::cout << "Player Details:" << std::endl;
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Level: " << m_level << std::endl;
    std::cout << "Force: " << m_force << std::endl;
    std::cout << "HP: " << m_hp << std::endl;
    std::cout << "Coins: " << m_coins << std::endl;
    std::cout << "------------------------" << std::endl;
}

void Player::levelUp()
{
    if (m_level < MAX_LEVEL)
    {
        m_level++;
    }
}

int Player::getLevel()
{
    return m_level;
}

void Player::buff(int forcePointsToUpgrade)
{
    m_force += forcePointsToUpgrade;
}

void Player::heal(int hpPointsToUpgrade)
{
    if (m_hp + hpPointsToUpgrade >= m_maxHp)
    {
        m_hp = m_maxHp;
        return;
    }
    m_hp += hpPointsToUpgrade;
}

void Player::damage(int hpPointsToDowngrade)
{
    if (m_hp - hpPointsToDowngrade <= 0)
    {
        m_hp = 0;
        return;
    }
    m_hp -= hpPointsToDowngrade;
}

bool Player::inKnockOut()
{
    if (m_hp == 0)
    {
        return true;
    }
    return false;
}

void Player::addCoins(int coinsToAdd)
{
    m_coins += coinsToAdd;
}

bool Player::pay(int coinsToPay)
{
    if (coinsToPay > m_coins)
    {
        return false;
    }
    m_coins -= coinsToPay;
    return true;
}

int Player::getAttackStrength()
{
    return m_force + m_level;
}