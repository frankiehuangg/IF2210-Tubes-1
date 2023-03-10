#include "header/Ability_Abilityless.hpp"

/**** Use ability, different for each card *****/
// Ubah status abilityCard pemain lain menjadi false
void Abilityless::useAbility(const Game &game)
{
    // Assumption we can access other player by its id from game object
    // I think this can avoid loop(?)
    // id -> new paramater of this function

    // Example:
    /*
    if (this->status) {
        game.players[id].ability.setStatus(false)
        this->setStatus(false);
    }
    */
}

/***** Print card *****/
// Print card info and status, if round = 1 print "NOT AVAILABLE or sum other shit idk"
void printCard()
{
    /*
    if (game.round = 1) {
        cout << "NOT AVAILABLE"
    } else {
        cout << "NAME     : ABILITYLESS" << endl;
        cout << "STATUS   : " << this->status << endl;
        cout << "ABILITY  : Mematikan kemampuan kartu lawan" << endl;
    }
    */
}