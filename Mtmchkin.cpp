#include "Mtmchkin.h"
const int INITIAL_CARD_INDEX = 0;
const int MAX_LEVEL = 10;

Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards) :

    m_player(playerName),
    m_cardsArray(cardsArray),
    m_numOfCards(numOfCards),
    m_currentCardIndex(INITIAL_CARD_INDEX),
    m_gameStatus(GameStatus::MidGame) {}

void Mtmchkin::playNextCard()
{
    Card currentCard = takeACardFromDeck();
    currentCard.printInfo();
    currentCard.applyEncounter(m_player);
    m_player.printInfo();

    if (m_player.getLevel() == MAX_LEVEL)
    {
        m_gameStatus = GameStatus::Win;
    }
    else if (m_player.isKnockedOut())
    {
        m_gameStatus = GameStatus::Loss;
    }
}

GameStatus Mtmchkin::getGameStatus() const
{
    return m_gameStatus;
}

bool Mtmchkin::isOver() const
{
    if (m_gameStatus == GameStatus::MidGame)
    {
        return false;
    }
    return true;
}

Card Mtmchkin::takeACardFromDeck()
{
    Card result = m_cardsArray[m_currentCardIndex];
    m_currentCardIndex++;
    if (m_currentCardIndex == m_numOfCards)
    {
        m_currentCardIndex = INITIAL_CARD_INDEX;
    }
    return result;
}

Mtmchkin::~Mtmchkin()
{
    delete m_cardsArray;
}
