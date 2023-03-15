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
    if (this->status && !this->isdisabled)
    {
        bool isAllAbilityCardUsed = true;
        for (int i = 1; i <= 7; i++)
        {
            if (game.getPlayerInTurn().getPlayerNumber() != i && game.getPlayer(i).getAbilityCardStatus())
            {
                isAllAbilityCardUsed = false;
            }
        }

        if (isAllAbilityCardUsed)
        {
            std::cout << "Eits, ternyata semua pemain sudah memakai kartu kemampuan." << std::endl;
            std::cout << "Yah kamu kena sendiri deh, kartumu dinonaktifkan oleh dirimu sendiri.🤣" << std::endl;
            this->disable();
        }
        else
        {
            std::cout << game.getPlayerInTurn().getPlayerName() << " akan mematikan kartu ability lawan!" << std ::endl;
            std::cout << "Silakan pilih pemain yang kartu abilitynya ingin dimatikan:" << std::endl;

            int index = 1;
            std::map<int, int> index_id;
            for (int i = 1; i <= 7; i++)
            {
                if (i != game.getPlayerInTurn().getPlayerNumber())
                {
                    std::cout << index << ". " << game.getPlayer(i).getPlayerName() << std::endl;
                    index_id[index] = i;
                    index++;
                }
            }

            string choicesRaw;
            bool isValidInputNumber = true;
            int choices;
            do
            {
                std::cout << "Mohon masukkan angka 1-6!" << std::endl;
                std::cout << "> ";
                getline(std::cin, choicesRaw);
                if (choicesRaw.length() == 1 && isdigit(choicesRaw[0]))
                {
                    choices = stoi(choicesRaw);
                }
                else
                {
                    isValidInputNumber = false;
                }
            } while (!isValidInputNumber || choices < 1 || choices > 6);

            bool statusOther = game.getPlayer(index_id[choices]).getAbilityCardStatus();
            if (statusOther)
            {
                game.getPlayer(index_id[choices]).setAbilityCardStatus(false);
                std::cout << "Kartu ability " << game.getPlayer(index_id[choices]).getPlayerName() << " telah dimatikan!" << std::endl;
                this->status = false;
            }
            else
            {
                std::cout << "Kartu ability " << game.getPlayer(index_id[choices]).getPlayerName() << " telah dipakai sebelumnya." << std::endl;
                std::cout << "Yah, sayang penggunaan kartu ini sia-sia🤣" << std::endl;
            }
        }
    }
    else if (this->isdisabled)
    {
        std::cout << "Yah.., sayang sekali kamu sudah menonaktifkan kartumu sendiri.😭🤣" << std::endl;
    }
    else
    {
        std::cout << "Kamu sudah menggunakan kartu ini sebelumnya. Gabisa pakai lagi, jangan maruk!😠" << std::endl;
    }
}

/***** Print card *****/
// Print card info and status
void Abilityless::printCard()
{
    std::cout << "NAME     : " << this->type << std::endl;
    std::cout << "STATUS   : " << (this->status && !this->isdisabled ? " Belum digunakan" : (!this->status ? " Sudah digunakan" : " Dinonaktifkan")) << std::endl;
    std::cout << "ABILITY  : Mematikan kemampuan kartu lawan" << std::endl;
}
