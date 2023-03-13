#include "header/Ability_Swap.hpp"

void Swap::useAbility(Game& game) 
{
    if (!this->getStatus()) 
    {
        cout << "Oops, kartu ability swapmu telah dimatikan sebelumnya :(" << endl
             << "Silahkan lakukan perintah lain." << endl;
    }
    else 
    {
        int playerCount = game.getPlayerCount();
        Player& currentPlayer = game.getPlayer();
        int playerNumber1, playerNumber2;
        vector<int> playerNumsTemp;

        cout << currentPlayer.getPlayerName() << " melakukan SWAPCARD!" << endl;

        /*** Ini mungkin dijadiin satu method aja biar modular ***/
        cout << "Silahkan pilih pemain yang kartunya ingin kamu tukar: " << endl;
        for (int i = 1, num = 1; i <= playerCount; i++, num++) 
        {
            Player playerLoop = game.getPlayer(i);

            if (playerLoop.getPlayerNumber() != currentPlayer.getPlayerNumber()) 
            {
                cout << num << ". " << playerLoop.getPlayerName() << endl;
                playerNumsTemp.push_back(playerLoop.getPlayerNumber());
            }
        }
        
        cout << "< " << endl;
        cin >> playerNumber1;
        /*********************************************************/

        if (playerNumber1 < 1 || playerNumber1 > playerNumsTemp.size()); 
        {
            throw PlayerNotExist();
        }

        Player& player1 = game.getPlayer(playerNumsTemp.at(playerNumber1 - 1));
        playerNumsTemp.erase(playerNumsTemp.begin() + playerNumber1 - 1);


        /*** Ini mungkin dijadiin satu method aja biar modular ***/
        cout << "Silahkan pilih pemain lain yang kartunya ingin kamu tukar: " << endl;
        for (int idx = 0; idx < playerNumsTemp.size(); idx++) 
        {
            cout << idx + 1 << ". " << game.getPlayer(playerNumsTemp.at(idx)).getPlayerName() << endl;
        }

        cout << "< " << endl;
        cin >> playerNumber2;   
        /*********************************************************/

        if (playerNumber2 < 1 || playerNumber2 > playerNumsTemp.size()); 
        {
            throw PlayerNotExist();
        }

        Player& player2 = game.getPlayer(playerNumsTemp.at(playerNumber2 - 1));


        /*** Ini mungkin dijadiin satu method aja biar modular ***/
        int option1, option2;
        
        cout << "Silakan pilih kartu kanan/kiri " << player1.getPlayerName() << endl;
        cout << "1. Kanan \n2. Kiri" << endl;
        cin >> option1;
        
        cout << "Silakan pilih kartu kanan/kiri " << player2.getPlayerName() << endl;
        cout << "1. Kanan \n2. Kiri" << endl;
        cin >> option2;
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
    cout << "STATUS   : " << this->status << endl;
    cout << "ABILITY  : Jika kamu memakai Ability Card ini, kamu bisa memilih dua pemain" << endl
         <<  "yang akan menukarkan masing-masing satu kartu secara acak" << endl; 
}
 