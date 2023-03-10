#include "header/Ability_Quarter.hpp"

/**** Use ability, different for each card *****/
// Ubah status abilityCard pemain lain menjadi false
void Quarter::useAbility(const Game &game)
{
    /*
    if (this->status) {
        int initialPoint = game.point;
        game.point /= 4; // Not sure between this or *= 0.25, but the type of point is int?
        this->setStatus(false);
        cout << "Point game berubah dari " << initialPoint << " menjadi " << game.point << endl;
    } else {
        cout << "Anda tidak dapat menggunakan ability ini." << endl;
    }
    */
}

/***** Print card *****/
// Print card info and status, if round = 1 print "NOT AVAILABLE or sum other shit idk"
void Quarter::printCard()
{
    /*
    if (game.round = 1) {
        cout << "NOT AVAILABLE"
    } else {
        cout << "NAME     : QUARTER" << endl;
        cout << "STATUS   : " << this->status << endl;
        cout << "ABILITY  : Menurunkan total poin hadiah menjadi 0.25x nilai saat ini" << endl;
    }
    */
}