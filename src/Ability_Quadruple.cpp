#include "header/Ability_Quadruple.hpp"
#include "header/Game.hpp"
#include <iostream>

Quadruple::Quadruple()
{
    type = "QUADRUPLE";
}

/**** Use ability, different for each card *****/
// Ubah status abilityCard pemain lain menjadi false
void Quadruple::useAbility(Game &game)
{
    if (this->status && !this->isdisabled)
    {
        int initialPoint = game.getPoint();
        game.setPoint(initialPoint * 4);
        this->status = false;
        std::cout << game.getPlayerInTurn().getPlayerName() << " melakukan QUADRUPLE!" << std::endl;
        std::cout << "Point hadiah naik dari " << initialPoint << " menjadi " << game.getPoint() << "!" << std::endl;
    }
    else if (this->isdisabled)
    {
        throw AbilityCardDisabled("Yah.., sayang sekali kartumu sudah dinonaktifkan oleh pemain lain.😭");
    }
    else
    {
        std::cout << "Kamu sudah menggunakan kartu ini sebelumnya. Gabisa pakai lagi, jangan maruk!😠" << std::endl;
    }
}

/***** Print card *****/
// Print card info and status
void Quadruple::printCard()
{
    std::cout << "NAME     \t: " << this->type << std::endl;
    std::cout << "STATUS   \t: " << (this->status && !this->isdisabled ? "Belum digunakan" : (!this->status ? "Sudah digunakan" : "Dinonaktifkan")) << std::endl;
    std::cout << "ABILITY  \t: Menaikkan total poin hadiah menjadi 4x lipat" << std::endl;
}
