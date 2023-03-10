#include "header/Ability_Quadruple.hpp"

/**** Use ability, different for each card *****/
// Ubah status abilityCard pemain lain menjadi false
void Quadruple::useAbility(const Game &game)
{
    // Assumption we can access other player by its id from game object
    // I think this can avoid loop(?)
    // id -> new paramater of this function

    // Example:
    /*
    if (this->status) {
        int initialPoint = game.point;
        game.point *= 4;
        this->setStatus(false);
        cout << "Point game berubah dari " << initialPoint << " menjadi " << game.point << endl;
    } else {
        cout << "Anda tidak dapat menggunakan ability ini." << endl;
    }
    */
}

/***** Print card *****/
// Print card info and status, if round = 1 print "NOT AVAILABLE or sum other shit idk"
void Quadruple::printCard()
{
    /*
    if (game.round = 1) {
        cout << "NOT AVAILABLE"
    } else {
        cout << "NAME     : QUADRUPLE" << endl;
        cout << "STATUS   : " << this->status << endl;
        cout << "ABILITY  : Menaikkan total poin hadiah menjadi 4x lipat" << endl;
    }
    */
}