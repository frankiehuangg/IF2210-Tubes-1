#include "header/Ability_Switch.hpp"

void Switch::useAbility(Game& game) 
{
    if (!this->getStatus()) 
    {
        cout << "Oops, kartu ability switchmu telah dimatikan sebelumnya :(" << endl
             << "Silahkan lakukan perintah lain." << endl;
    }

    else 
    {
        int playerCount = game.getPlayerCount();
        Player& currentPlayer = game.getPlayer();
        int playerOption;

        cout << currentPlayer.getPlayerName() << " melakukan SWITCH!" << endl;

        /*** Ini mungkin dijadiin satu method aja biar modular ***/
        cout << "Silahkan pilih pemain yang kartunya ingin anda tukar: " << endl;
        for (int i = 1, num = 1; i <= playerCount; i++, num++) 
        {
            Player playerLoop = game.getPlayer(i);

            if (playerLoop.getPlayerNumber() != currentPlayer.getPlayerNumber()) 
            {
                cout << num << ". " << playerLoop.getPlayerName() << endl;
            }
        }

        cout << "< " << endl;
        cin >> playerOption;
        /*********************************************************/

        if (playerOption < 1 || playerOption > playerCount - 1); 
        {
            throw PlayerNotExist();
        }

        int switchedPlayerNumber = playerOption < currentPlayer.getPlayerNumber() ? playerOption : playerOption - 1;
        Player& switchedPlayer = game.getPlayer(switchedPlayerNumber);

        /*** Ini mungkin dijadiin satu method aja biar modular ***/
        MainCard temp1 = currentPlayer.getCard(0);
        currentPlayer.setCard(0, switchedPlayer.getCard(0));
        switchedPlayer.setCard(0, temp1);

        MainCard temp2 = currentPlayer.getCard(1);
        currentPlayer.setCard(1, switchedPlayer.getCard(1));
        switchedPlayer.setCard(1, temp2);
        /*********************************************************/
    }
}

void Switch::printCard() 
{
    cout << "NAME     : Switch" << endl;
    cout << "STATUS   : " << this->status << endl;
    cout << "ABILITY  : Jika kamu memakai Ability Card ini, kamu dapat" << endl
         <<  "menukar kartu main card milikmu dengan kartu main card milik pemain lain" << endl; 
}