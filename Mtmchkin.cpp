#include "Mtmchkin.h"
const int INITIAL_CARD_INDEX = 0;

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) :
    m_player(playerName)
{
    m_cardsArray = cardsArray;
    m_numOfCards = numOfCards;
    m_gameStatus = GameStatus::MidGame;
    m_nextCardIndex = INITIAL_CARD_INDEX;
}

GameStatus Mtmchkin::getGameStatus() const
{
    return m_gameStatus;
}
