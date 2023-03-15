#include "header/Ability_Swap.hpp"
#include "header/Game.hpp"

Swap::Swap(){
    type = "SWAPCARD";
}

void Swap::useAbility(Game& game) 
{
    if (!this->getStatus())
    {
        cout << "Oops, kartu ability swapmu telah dimatikan sebelumnya :(" << endl
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

                cout << "> ";
                string inputNumber1;
                cin >> inputNumber1;
                if (isdigit(inputNumber1[0]) && inputNumber1.length() == 1) 
                {
                    playerNumber1 = inputNumber1[0] - '0';
                    if (playerNumber1 >= currentPlayer.getPlayerNumber()) 
                    {
                        ++playerNumber1;
                    }
                    game.getPlayer(playerNumber1); // Kalo ga berhasil akan throw PlayerNotExist
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
                cout << "> ";
                string inputNumber2;
                cin >> inputNumber2;
                if (isdigit(inputNumber2[0]) && inputNumber2.length() == 1) 
                {
                    playerNumber2 = inputNumber2[0] - '0';
                    game.getPlayer(playerNumsTemp[playerNumber2 - 1]); // Kalo ga berhasil akan throw PlayerNotExist
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
                playerNumsTemp.clear();
            }
        }
        
        Player &player2 = game.getPlayer(playerNumsTemp[playerNumber2 - 1]);
        /*********************************************************/


        

        /*** Ini mungkin dijadiin satu method aja biar modular ***/
        string inputOption1, inputOption2;
        int option1, option2;
        valid = false;

        do
        {
            cout << "Silakan pilih kartu kanan/kiri " << player1.getPlayerName() << endl;
            cout << "1. Kanan \n2. Kiri" << endl;
            cin >> inputOption1;
            if (inputOption1.length() == 1 && isdigit(inputOption1[0])) 
            {
                option1 = inputOption1[0] - '0';
                if (option1 == 1 || option1 == 2) valid = true;
            }
            else 
            {
                cout << "Masukan tidak valid" << endl;
            }
        } while(!valid);

        do
        {
            cout << "Silakan pilih kartu kanan/kiri " << player2.getPlayerName() << endl;
            cout << "1. Kanan \n2. Kiri" << endl;
            cin >> inputOption2;
            if (inputOption2.length() == 1 && isdigit(inputOption2[0])) 
            {
                option2 = inputOption2[0] - '0';
                if (option2 == 1 || option2 == 2) valid = true;
            }
            else 
            {
                cout << "Masukan tidak valid" << endl;
            }
        } while(!valid);
       

        /*********************************************************/

        // Swap kartu pemain_1 dengan pemain_2 (Mungkin juga bisa dibikin satu method)
        MainCard temp = player1.getCard(option1 - 1);
        player1.setCard(option1 - 1, player2.getCard(option2 - 1));
        player2.setCard(option2 - 1, temp);
        this->setStatus(false);
    }
}

void Swap::printCard()
{
    cout << "NAME     : SWAP" << endl;
    cout << "STATUS   : " << (this->status ? " Belum digunakan" : " Sudah digunakan") << endl;
    cout << "ABILITY  : memilih dua pemain yang akan menukarkan masing-masing satu kartu secara acak" << endl;
}
