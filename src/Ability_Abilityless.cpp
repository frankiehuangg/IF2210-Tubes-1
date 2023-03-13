#include "header/Ability_Abilityless.hpp"
#include <iostream>

using namespace std;

/**** Use ability, different for each card *****/
// Ubah status abilityCard pemain lain menjadi false
void Abilityless::useAbility(Game &game)
{
    // Assumption we can access other player by its id from game object
    // I think this can avoid loop(?)
    // id -> new paramater of this function

    // Interface
    // Example:
    /*
    if (this->status) {
        bool statusOther = game.players[id].ability.status
        if (statusOrder) {
            game.players[id].ability.setStatus(false)
            cout << "Pemain " << game.players[id].name << " telah dinonaktifkan abilitynya." << endl;
        } else {
            cout << "Pemain " << game.players[id].name << " tidak memiliki ability card yang dapat digunakan" << endl;
        }
        this->setStatus(false);
    } else {
        cout << "Anda tidak dapat menggunakan ability ini." << endl;
    }
    */
}

/***** Print card *****/
// Print card info and status, if round = 1 print "NOT AVAILABLE or sum other shit idk"
void Abilityless::printCard()
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