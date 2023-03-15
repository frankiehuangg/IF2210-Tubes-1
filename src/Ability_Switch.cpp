#include "header/Ability_Switch.hpp"
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
        cout << "Yah.., sayang sekali kartumu sudah dinonaktifkan oleh pemain lain.😭" << std::endl;
    }
    else
    {
        int playerCount = game.getPlayerCount();
        Player &currentPlayer = game.getPlayerInTurn();
        int playerOption;

        cout << currentPlayer.getPlayerName() << " melakukan SWITCH!" << endl;

        /*** Ini mungkin dijadiin satu method aja biar modular ***/
        bool valid = false;
        while (!valid)
        {
            try
            {
                cout << "Silahkan pilih pemain yang kartunya ingin anda tukar: " << endl;
                int num = 1;
                for (int i = 1; i <= playerCount; i++)
                {
                    Player playerLoop = game.getPlayer(i);

                    if (playerLoop.getPlayerNumber() != currentPlayer.getPlayerNumber())
                    {
                        cout << num << ". " << playerLoop.getPlayerName() << endl;
                        ++num;
                    }
                }
                cout << "> ";
                string inputOption;
                cin >> inputOption;
                if (isdigit(inputOption[0]) && inputOption.length() == 1)
                {
                    playerOption = inputOption[0] - '0';
                    if (playerOption >= currentPlayer.getPlayerNumber())
                        ++playerOption;
                    game.getPlayer(playerOption); // Kalo ga berhasil akan throw PlayerNotExist
                    valid = true;
                }
                else
                {
                    cout << "Masukan tidak valid. Ulangi!" << endl;
                }
            }
            catch (PlayerNotExist &e)
            {
                cout << "Pemain tidak ditemukan. Ulangi!" << endl;
            }
        }

        Player &switchedPlayer = game.getPlayer(playerOption);
        /*********************************************************/

        /*** Ini mungkin dijadiin satu method aja biar modular ***/
        MainCard temp1 = currentPlayer.getCard(0);
        currentPlayer.setCard(0, switchedPlayer.getCard(0));
        switchedPlayer.setCard(0, temp1);

        MainCard temp2 = currentPlayer.getCard(1);
        currentPlayer.setCard(1, switchedPlayer.getCard(1));
        switchedPlayer.setCard(1, temp2);
        /*********************************************************/

        this->setStatus(false);
    }
}

void Switch::printCard()
{
    cout << "NAME     : " << this->type << endl;
    cout << "STATUS   : " << (this->status && !this->isdisabled ? "Belum digunakan" : (!this->status ? "Sudah digunakan" : "Dinonaktifkan")) << endl;
    cout << "ABILITY  : Menukar main card milikmu denganmain card milik pemain lain" << endl;
}
