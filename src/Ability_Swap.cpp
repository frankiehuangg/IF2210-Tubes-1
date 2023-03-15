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
    else if (this->isdisabled)
    {
        cout << "Yah.., sayang sekali kartumu sudah dinonaktifkan oleh pemain lain.😭" << std::endl;
    }
    else
    {
        Player &currentPlayer = game.getPlayerInTurn();
        int currentPlayerNum = currentPlayer.getPlayerNumber();
        int playerNumber1, playerNumber2;

        cout << currentPlayer.getPlayerName() << " melakukan SWAPCARD!" << endl;

        // Mendapatkan input player yang akan diswap
        playerNumber1 = inputPlayerToSwap(game, currentPlayerNum);
        Player &player1 = game.getPlayer(playerNumber1);

        playerNumber2 = inputPlayerToSwap(game, currentPlayerNum, playerNumber1);
        Player &player2 = game.getPlayer(playerNumber2);

        // Mendapatkan input kartu mana yang akan diswap (kiri/kanan)
        IOHandler<int> optionIO;
        int option1, option2;

        cout << "Silakan pilih kartu kiri/kanan " << player1.getPlayerName() << endl;
        cout << "1. Kiri \n2. Kanan" << endl;
        option1 = optionIO.getInputInAccepted(1, 2);

        cout << "Silakan pilih kartu kiri/kanan " << player2.getPlayerName() << endl;
        cout << "1. Kiri \n2. Kanan" << endl;
        option2 = optionIO.getInputInAccepted(1, 2);

        // Swap kartu pemain_1 dengan pemain_2 (Mungkin juga bisa dibikin satu method)
        MainCard temp = player1.getCard(option1 - 1);
        player1.setCard(option1 - 1, player2.getCard(option2 - 1));
        player2.setCard(option2 - 1, temp);
        this->setStatus(false);
    }
}

void Swap::printCard()
{
    cout << "NAME     : " << this->type << endl;
    cout << "STATUS   : " << (this->status && !this->isdisabled ? "Belum digunakan" : (!this->status ? "Sudah digunakan" : "Dinonaktifkan")) << endl;
    cout << "ABILITY  : memilih dua pemain yang akan menukarkan masing-masing satu kartu secara acak" << endl;
}

int Swap::inputPlayerToSwap(Game &game, int currentPlayerNum)
{
    int playerNumber;
    int playerCount = game.getPlayerCount();
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
                if (playerLoop.getPlayerNumber() != currentPlayerNum)
                {
                    cout << num << ". " << playerLoop.getPlayerName() << endl;
                    ++num;
                }
            }

            cout << "> ";
            string inputNumber;
            cin >> inputNumber;
            if (isdigit(inputNumber[0]) && inputNumber.length() == 1)
            {
                playerNumber = inputNumber[0] - '0';
                if (playerNumber >= currentPlayerNum)
                    ++playerNumber;
                game.getPlayer(playerNumber); // Kalo ga berhasil akan throw PlayerNotExist
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

    return playerNumber;
}

int Swap::inputPlayerToSwap(Game &game, int currentPlayerNum, int alreadySelectedPlayerNum)
{
    int playerOption, playerNumber;
    vector<int> playerNumsTemp;
    int playerCount = game.getPlayerCount();
    bool valid = false;
    while (!valid)
    {
        try
        {
            cout << "Silahkan pilih pemain lain yang kartunya ingin kamu tukar: " << endl;
            int num = 1;
            for (int i = 1; i <= playerCount; i++)
            {
                Player &playerLoop = game.getPlayer(i);
                if (playerLoop.getPlayerNumber() != currentPlayerNum &&
                    playerLoop.getPlayerNumber() != alreadySelectedPlayerNum)
                {
                    cout << num << ". " << playerLoop.getPlayerName() << endl;
                    ++num;
                    playerNumsTemp.push_back(playerLoop.getPlayerNumber());
                }
            }
            cout << "> ";
            string inputNumber;
            cin >> inputNumber;
            if (isdigit(inputNumber[0]) && inputNumber.length() == 1)
            {
                playerOption = inputNumber[0] - '0';
                playerNumber = playerNumsTemp[playerOption - 1];
                game.getPlayer(playerNumber); // Kalo ga berhasil akan throw PlayerNotExist
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

    return playerNumber;
}