#include "header/Ability_Quarter.hpp"
#include "header/Game.hpp"
#include <iostream>

/**** Use ability, different for each card *****/
// Ubah status abilityCard pemain lain menjadi false
void Quarter::useAbility(Game &game)
{
    if (this->status)
    {
        int initialPoint = game.getPoint();
        // Di spek tidak dibatasi point harus > 3
        game.setPoint(initialPoint / 4);
        this->status = false;
        std::cout << game.getPlayer().getPlayerName() << " melakukan QUARTER!" << std::endl;
        std::cout << "Point hadiah turun dari " << initialPoint << " menjadi " << game.getPoint() << "!" << std::endl;
    }
    else
    {
        std::cout << "Anda tidak dapat menggunakan ability QUARTER. Ability sudah digunakan" << std::endl;
    }
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
