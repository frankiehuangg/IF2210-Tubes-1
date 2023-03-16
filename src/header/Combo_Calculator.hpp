#include "Combo.hpp"

class ComboCalculator:public Table{
    private:
    vector<MainCard> stored;
    vector<Player> players;
    vector<Combo> combos;
    float value;
    string comboType;
    int playerNum;

    public:
    /* ComboCalculator constructor */
    ComboCalculator(){}

    /* Start the module */
    void start();

    /* Calculate all combos */
    void calculate();

    /* Announce winner */
    void announce();

    /* Input a certain amount of card 
     * @param int amount        Amount of card to be input */
    void getCard(int);

};
