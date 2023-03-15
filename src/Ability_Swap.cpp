#include "header/Ability_Swap.hpp"
#include "header/Game.hpp"

Swap::Swap()
{
    type = "SWAPCARD";
}

void Swap::useAbility(Game &game)
{
    if (!this->getStatus())
    {
        cout << "Oops, kartu ability swapmu telah dimatikan sebelumnya :(" << endl
             << "Silahkan lakukan perintah lain." << endl;
    }
    else
    {
        int playerCount = game.getPlayerCount();
        Player &currentPlayer = game.getPlayer();
        int playerNumber1, playerNumber2;

        cout << currentPlayer.getPlayerName() << " melakukan SWAPCARD!" << endl;

        /*** Ini mungkin dijadiin satu method aja biar modular ***/
        bool valid = false;
        while (!valid)
        {
            try
            {
                cout << "Silahkan pilih pemain yang kartunya ingin kamu tukar: " << endl;
                int num = 1;
                for (int i = 1; i <= playerCount; i++)
                {
                    Player &playerLoop = game.getPlayer(i);
                    if (playerLoop.getPlayerNumber() != currentPlayer.getPlayerNumber())
                    {
                        cout << num << ". " << playerLoop.getPlayerName() << endl;
                        ++num;
                    }
                }

                cout << "< ";
                cin >> playerNumber1;
                if (playerNumber1 >= currentPlayer.getPlayerNumber())
                {
                    ++playerNumber1;
                }

                game.getPlayer(playerNumber1); // Kalo ga berhasil akan throw PlayerNotExist
                valid = true;
            }
            catch (PlayerNotExist &e)
            {
                cout << "Masukan pemain tidak valid. Ulangi!" << endl;
            }
        }

        Player &player1 = game.getPlayer(playerNumber1);
        /*********************************************************/

        /*** Ini mungkin dijadiin satu method aja biar modular ***/
        vector<int> playerNumsTemp;
        valid = false;
        while (!valid)
        {
            try
            {
                cout << "Silahkan pilih pemain lain yang kartunya ingin kamu tukar: " << endl;
                int num = 1;
                for (int i = 1; i <= playerCount; i++)
                {
                    Player &playerLoop = game.getPlayer(i);
                    if (playerLoop.getPlayerNumber() != currentPlayer.getPlayerNumber() &&
                        playerLoop.getPlayerNumber() != playerNumber1)
                    {
                        cout << num << ". " << playerLoop.getPlayerName() << endl;
                        ++num;
                        playerNumsTemp.push_back(playerLoop.getPlayerNumber());
                    }
                }
                cout << "< ";
                cin >> playerNumber2;
                game.getPlayer(playerNumsTemp[playerNumber2 - 1]); // Kalo ga berhasil akan throw PlayerNotExist
                valid = true;
            }
            catch (PlayerNotExist &e)
            {
                cout << "Masukan pemain tidak valid. Ulangi!" << endl;
                playerNumsTemp.clear();
            }
        }

        Player &player2 = game.getPlayer(playerNumsTemp[playerNumber2 - 1]);
        /*********************************************************/

        /*** Ini mungkin dijadiin satu method aja biar modular ***/
        int option1, option2;

        IOHandler<int> optionIO;

        cout << "Silakan pilih kartu kanan/kiri " << player1.getPlayerName() << endl;
        cout << "1. Kanan \n2. Kiri" << endl;
        option1=optionIO.getInputInAccepted(1,2);

        cout << "Silakan pilih kartu kanan/kiri " << player2.getPlayerName() << endl;
        cout << "1. Kanan \n2. Kiri" << endl;
        option2=optionIO.getInputInAccepted(1,2);
        /*********************************************************/

        // Swap kartu pemain_1 dengan pemain_2 (Mungkin juga bisa dibikin satu method)
        MainCard temp = player1.getCard(option1 - 1);
        player1.setCard(option1 - 1, player2.getCard(option2 - 1));
        player2.setCard(option2 - 1, temp);
    }
}

void Swap::printCard()
{
    cout << "NAME     : Swap" << endl;
    cout << "STATUS   : " << (this->status && !this->isdisabled ? " Belum digunakan" : (!this->status ? " Sudah digunakan" : " Dinonaktifkan")) << endl;
    cout << "ABILITY  : Jika kamu memakai Ability Card ini, kamu bisa memilih dua pemain" << endl
         << "yang akan menukarkan masing-masing satu kartu secara acak" << endl;
}
