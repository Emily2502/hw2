#ifndef HW2_PLAYER_H
#define HW2_PLAYER_H
const int DEFAULT_FORCE = 5;
const int DEFAULT_MAX_HP = 100;

class Player {

public:
    /**
     * C'tor of Player class
     *
     * @param name - The name of the player.
     * @param maxHp - The maximum HP possible for the player.
     * @param force - The force of the player.
     * @return
     *      A new instance of Player.
    */
    explicit Player(const char* name, int maxHp = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);

    /**
     * Copy c'tor of Player class
     *
     * @param Player& - Reference to player to copy.
     * @return
     *      A new instance of Player.
    */
    Player(const Player&) = default;

    /**
     * D'tor of Player class
     *
     * @return
     *      void
    */
    ~Player();

    /**
     * assignment operator for Player class
    */
    Player& operator=(const Player&) = default;
    // TODO: free char* name

    /**
     * Prints information of a Player in the following format:
     *
     * Player Details:
     * Name:
     * Level:
     * Force:
     * HP:
     * Coins:
     * ------------------------
     *
     * @return
     *      void
    */
    void printPlayerInfo() const;

    /**
     * Increases the level of a player by one
     * if player's level is at maximum value already nothing will be done
     *
     * @return
     *      void
    */
    void levelUp();

    /**
     * Gets the level of a player
     *
     * @return
     *      level of said player
    */
    int getLevel() const;

    /**
     * Increases the force of a player
     *
     * @param forcePointsToUpgrade - Number of points to increase player's force by.
     * @return
     *      void
    */
    void buff(int forcePointsToUpgrade);

    /**
     * Increases HP of a player
     *
     * @param hpPointsToUpgrade - Number of points to increase player's HP by.
     * @return
     *      void
    */
    void heal(int hpPointsToUpgrade);

    /**
     * Decreases HP of a player
     *
     * @param hpPointsToDowngrade - Number of points to decrease player's HP by.
     * @return
     *      void
    */
    void damage(int hpPointsToDowngrade);

    /**
     * Checks if HP of a player is zero
     *
     * @return
     *      true - if HP of said player is zero
     *      false - otherwise
    */
    bool isKnockOut() const;

    /**
     * Increases number of coins of a player
     *
     * @param coinsToAdd - Number of points to increase player's coins by.
     * @return
     *      void
    */
    void addCoins(int coinsToAdd);

    /**
     * Makes a player pay
     * if said player has enough coins then this function decreases the number of coins
     * they have.
     *
     * @param coinsToPay - Number of points to a player has to pay.
     * @return
     *      true - if said player has enough coins
     *      false - otherwise
    */
    bool pay(int coinsToPay);

    /**
     * Gets attack strength of a player
     * attack strength is define by force + level
     *
     * @return
     *      attack strength of said player
    */
    int getAttackStrength() const;

private:
    const char* m_name;  /** English letters. no spaces */
    int m_hp;  /** [0,maxHp] */
    int m_level;  /** [1,10] */
    int m_force;  /** natural number */
    int m_maxHp;  /** natural number */
    int m_coins;  /** non-negative integer */
};

#endif //HW2_PLAYER_H
