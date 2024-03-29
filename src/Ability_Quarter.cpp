#include "header/Ability_Quarter.hpp"
#include "header/Game.hpp"

Quarter::Quarter()
{
    type = "QUARTER";
}

/**** Use ability, different for each card *****/
// Ubah status abilityCard pemain lain menjadi false
void Quarter::useAbility(Game &game)
{
    if (this->status && !this->isdisabled)
    {
        long long initialPoint = game.getPoint();
        if (initialPoint > 3)
        {
            game.setPoint(initialPoint / 4);
        }
        else
        {
            game.setPoint(1);
        }
        this->status = false;
        std::cout << game.getPlayerInTurn().getPlayerName() << " melakukan QUARTER!" << std::endl;
        std::cout << "Point hadiah turun dari " << initialPoint << " menjadi " << game.getPoint() << "!" << std::endl;
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
void Quarter::printCard()
{
    std::cout << "NAME     \t: " << this->type << std::endl;
    std::cout << "STATUS   \t: " << (this->status && !this->isdisabled ? "Belum digunakan" : (!this->status ? "Sudah digunakan" : "Dinonaktifkan")) << std::endl;
    std::cout << "ABILITY  \t: Menurunkan total poin hadiah menjadi 0.25x nilai saat ini" << std::endl;
}
