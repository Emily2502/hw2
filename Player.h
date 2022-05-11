#ifndef HW2_PLAYER_H
#define HW2_PLAYER_H


class Player {

    char* m_name; /** English letters. no spaces */
    int m_HP; /** [0,maxHP] */
    int m_level; /** [1,10] */
    int m_force; /** natural number */
    int m_maxHP; /** natural number */
    int m_coins; /** non-negative integer */


    public:
    Player(char* name, int max_hp = 100 ,int force=5);


};








#endif //HW2_PLAYER_H
