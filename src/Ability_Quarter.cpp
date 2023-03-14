#include "header/Ability_Quarter.hpp"
#include "header/Game.hpp"

/**** Use ability, different for each card *****/
// Ubah status abilityCard pemain lain menjadi false
void Quarter::useAbility(Game &game)
{
    if (this->status)
    {
        int initialPoint = game.getPoint();
        if (initialPoint > 3)
        {
            game.setPoint(initialPoint / 4);
        }
        else
        {
            game.setPoint(1);
        }
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
// Print card info and status
void Quarter::printCard()
{
    std::cout << "NAME     : QUARTER" << std::endl;
    std::cout << "STATUS   : " << (this->status ? " Belum digunakan" : " Sudah diguankan") << std::endl;
    std::cout << "ABILITY  : Menurunkan total poin hadiah menjadi 0.25x nilai saat ini" << std::endl;
}
