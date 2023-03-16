#include "header/Ability_Switch.hpp"
#include "header/Ability_Swap.hpp"
#include "header/Game.hpp"

Switch::Switch()
{
    type = "SWITCH";
}

void Switch::useAbility(Game &game)
{
    if (!this->getStatus())
    {
        cout << "Oops, kartu ability switchmu telah dimatikan sebelumnya :(" << endl
             << "Silahkan lakukan perintah lain." << endl;
    }
    else if (this->isdisabled)
    {
        throw AbilityCardDisabled("Yah.., sayang sekali kartumu sudah dinonaktifkan oleh pemain lain.😭");
    }
    else
    {
        Player &currentPlayer = game.getPlayerInTurn();
        int currentPlayerNum = currentPlayer.getPlayerNumber();
        int playerOption;

        cout << currentPlayer.getPlayerName() << " melakukan SWITCH!" << endl;

        // Mendapatkan input player yang akan diswap
        string outputMsg = "Silahkan pilih pemain yang kartunya ingin anda tukar: ";
        playerOption = Swap::inputPlayerToSwap(game, currentPlayerNum, 0, outputMsg);
        Player &switchedPlayer = game.getPlayer(playerOption);
        int switchedPlayerNum = switchedPlayer.getPlayerNumber();

        // Menukar kartu pemain yang dipilih dengan pemain yang melakukan switch
        Swap::swapCardAtIdx(game, currentPlayerNum, switchedPlayerNum, 1, 1);
        Swap::swapCardAtIdx(game, currentPlayerNum, switchedPlayerNum, 2, 2);

        this->setStatus(false);
    }

    cout << "Kartu pemain baru:" << endl;
    cout << game.getPlayer().getInventoryCards();
}

void Switch::printCard()
{
    cout << "NAME     \t: " << this->type << endl;
    cout << "STATUS   \t: " << (this->status && !this->isdisabled ? "Belum digunakan" : (!this->status ? "Sudah digunakan" : "Dinonaktifkan")) << endl;
    cout << "ABILITY  \t: Menukar main card milikmu denganmain card milik pemain lain" << endl;
}
