#ifndef HW2_PLAYER_H
#define HW2_PLAYER_H
#define DEFAULT_FORCE 5
#define DEFAULT_MAX_HP 100

class Player {

    const char* m_name; /** English letters. no spaces */
    int m_hp; /** [0,maxHP] */
    int m_level; /** [1,10] */
    int m_force; /** natural number */
    int m_maxHp; /** natural number */
    int m_coins; /** non-negative integer */


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
    Player(const char* name, int maxHp = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);

    /**
     * Copy c'tor of Player class
     *
     * @param Player& - Reference to plaer we wish to copy.
     * @return
     *      A new instance of Player.
    */
    Player(const Player&);

    /**
     * d'tor of Player class
    */
    ~Player();

    Player& operator=(const Player&);
    void printPlayerInfo();
    void levelUp();
    int getLevel();
    void buff(int forcePointsToUpgrade);
    void heal(int hpPointsToUpgrade);
    void damage(int hpPointsToDowngrade);
    bool inKnockOut();
    void addCoins(int coinsToAdd);
    bool pay(int coinsToPay);
    int getAttackStrength();
};








#endif //HW2_PLAYER_H
