#include "header/Ability_Abilityless.hpp"
#include "header/Game.hpp"

Abilityless::Abilityless()
{
    type = "ABILITYLESS";
}

/**** Use ability, different for each card *****/
// Ubah status abilityCard pemain lain menjadi false
void Abilityless::useAbility(Game &game)
{
    if (!this->status)
    {
        bool isAllAbilityCardUsed = true;
        for (int i = 1; i < 7; i++)
        {
            if (game.getPlayer(i).getAbilityCardStatus())
            {
                isAllAbilityCardUsed = false;
            }
        }

        if (isAllAbilityCardUsed)
        {
            std::cout << "Eits, ternyata semua pemain sudah memakai kartu kemampuan." << std::endl;
            std::cout << "Yah kamu kena sendiri deh, kemampuanmu menjadi abilityless." << std::endl;
            std::cout << "Yah, penggunaan kartu ini sia-sia." << std::endl;
            this->status = true;
        }
        else
        {
            std::cout << game.getPlayer().getPlayerName() << " akan mematikan kartu ability lawan!" << std ::endl;
            std::cout << "Silakan pilih pemain yang kartu abilitynya ingin dimatikan:" << std::endl;

            for (int i = 1; i < 7; i++)
            {
                std::cout << i << ". " << game.getPlayer(i).getPlayerName() << std::endl;
            }

            int choices;
            do
            {
                std::cout << "Mohon masukkan angka 1-7!" << std::endl;
                std::cout << "> ";
                std::cin >> choices;
            } while (choices < 1 || choices > 6);

            bool statusOther = game.getPlayer(choices).getAbilityCardStatus();
            if (statusOther)
            {
                game.getPlayer(choices).setAbilityCardStatus(false);
                std::cout << "Kartu ability " << game.getPlayer(choices).getPlayerName() << " telah dimatikan!" << std::endl;
                this->status = true;
            }
            else
            {
                std::cout << "Kartu ability " << game.getPlayer(choices).getPlayerName() << " telah dipakai sebelumnya." << std::endl;
                std::cout << "Yah, sayang penggunaan kartu ini sia-sia🤣" << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Anda tidak dapat menggunakan ability ABILITYLESS. Ability sudah digunakan" << std::endl;
    }
}

/***** Print card *****/
// Print card info and status
void Abilityless::printCard()
{
    std::cout << "NAME     : ABILITYLESS" << std::endl;
    std::cout << "STATUS   : " << (!this->status ? " Belum digunakan" : " Sudah diguankan") << std::endl;
    std::cout << "ABILITY  : Mematikan kemampuan kartu lawan" << std::endl;
}
