#include "header/Ability_Quadruple.hpp"
#include "header/Game.hpp"
#include <iostream>

/**** Use ability, different for each card *****/
// Ubah status abilityCard pemain lain menjadi false
void Quadruple::useAbility(Game &game)
{
    if (this->status)
    {
        int initialPoint = game.getPoint();
        game.setPoint(initialPoint * 4);
        this->status = false;
        std::cout << game.getPlayer().getPlayerName() << " melakukan QUADRUPLE!" << std::endl;
        std::cout << "Point hadiah naik dari " << initialPoint << " menjadi " << game.getPoint() << "!" << std::endl;
    }
    else
    {
        std::cout << "Anda tidak dapat menggunakan ability QUADRUPLE. Ability sudah digunakan" << std::endl;
    }
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
