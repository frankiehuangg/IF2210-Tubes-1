#include "header/Ability_Quadruple.hpp"
#include "header/Game.hpp"
#include <iostream>

Quadruple::Quadruple(){
    type = "QUADRUPLE";
}

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
// Print card info and status
void Quadruple::printCard()
{
    std::cout << "NAME     : QUADRUPLE" << std::endl;
    std::cout << "STATUS   : " << (this->status ? " Belum digunakan" : " Sudah diguankan") << std::endl;
    std::cout << "ABILITY  : Menaikkan total poin hadiah menjadi 4x lipat" << std::endl;
}
