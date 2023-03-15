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
        bool isAllAbilityCardUsedOrDisabled = true;
        for (int i = 1; i <= 7; i++)
        {
            if (game.getPlayerInTurn().getPlayerNumber() != i && game.getPlayer(i).getAbilityCardStatus() && !game.getPlayer(i).abilityDisabled())
            {
                isAllAbilityCardUsedOrDisabled = false;
            }
        }

        if (isAllAbilityCardUsedOrDisabled)
        {
            std::cout << "Eits, ternyata semua pemain sudah memakai kartu kemampuan." << std::endl;
            std::cout << "Yah kamu kena sendiri deh, kartumu dinonaktifkan oleh dirimu sendiri.🤣" << std::endl;
            this->disable();
        }
        else
        {
            std::cout << game.getPlayerInTurn().getPlayerName() << " akan menonaktifkan kartu ability lawan!" << std ::endl;
            std::cout << "Silakan pilih pemain yang kartu abilitynya ingin dinonaktifkan:" << std::endl;

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

            int choices;
            IOHandler<int> intIO;
            choices=intIO.getInputInAccepted(1,6);

            bool isOtherDisabled = game.getPlayer(index_id[choices]).abilityDisabled();
            bool statusOther = game.getPlayer(index_id[choices]).getAbilityCardStatus();
            if (statusOther && !isOtherDisabled)
            {
                game.getPlayer(index_id[choices]).disableAbilityCard();
                std::cout << "Kartu ability " << game.getPlayer(index_id[choices]).getPlayerName() << " telah dinonaktifkan!" << std::endl;
                this->status = false;
            }
            else if (!statusOther)
            {
                std::cout << "Kartu ability " << game.getPlayer(index_id[choices]).getPlayerName() << " telah dipakai sebelumnya." << std::endl;
                std::cout << "Yah, nyerangnya gagal deh..🤣" << std::endl;
            }
            else
            {
                std::cout << "Kartu ability " << game.getPlayer(index_id[choices]).getPlayerName() << " telah dinonaktifkan." << std::endl;
                std::cout << "Yah, nyerangnya gagal deh..🤣" << std::endl;
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
    std::cout << "ABILITY  : Menonaktifkan kemampuan kartu lawan" << std::endl;
}
