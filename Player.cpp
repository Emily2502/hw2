#include "Player.h"
#define INITIAL_LEVEL 1
#define INITIAL_COINS 0

Player::Player(char *name, int max_hp ,int force)
{
    m_name = name;
    m_level = INITIAL_LEVEL;
    m_coins = INITIAL_COINS;
    m_force = force;
    m_maxHP = max_hp;
    m_HP = max_hp;
}