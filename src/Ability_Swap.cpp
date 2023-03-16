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
        throw AbilityCardDisabled("Yah.., sayang sekali kartumu sudah dinonaktifkan oleh pemain lain.😭");
    }
    else
    {
        Player &currentPlayer = game.getPlayerInTurn();
        int currentPlayerNum = currentPlayer.getPlayerNumber();
        int playerNumber1, playerNumber2;

        cout << currentPlayer.getPlayerName() << " melakukan SWAPCARD!" << endl;

        // Mendapatkan input player yang akan diswap
        string outputMsg = "Silahkan pilih pemain yang kartunya ingin kamu tukar: ";
        playerNumber1 = inputPlayerToSwap(game, currentPlayerNum, 0, outputMsg);
        Player &player1 = game.getPlayer(playerNumber1);

        outputMsg = "Silahkan pilih pemain lain yang kartunya ingin kamu tukar: ";
        playerNumber2 = inputPlayerToSwap(game, currentPlayerNum, playerNumber1, outputMsg);
        Player &player2 = game.getPlayer(playerNumber2);

        // Mendapatkan input kartu mana yang akan diswap (kiri/kanan)
        IOHandler<int> optionIO;
        int option1, option2;

        cout << "Silakan pilih kartu kiri/kanan " << player1.getPlayerName() << endl;
        cout << "1. Kanan \n2. Kiri" << endl;
        option1 = optionIO.getInputInAccepted(1, 2);

        cout << "Silakan pilih kartu kiri/kanan " << player2.getPlayerName() << endl;
        cout << "1. Kanan \n2. Kiri" << endl;
        option2 = optionIO.getInputInAccepted(1, 2);

        // Swap kartu pemain_1 dengan pemain_2
        swapCardAtIdx(game, playerNumber1, playerNumber2, option1, option2);
        this->setStatus(false);
    }
}

void Swap::printCard()
{
    cout << "NAME     \t: " << this->type << endl;
    cout << "STATUS   \t: " << (this->status && !this->isdisabled ? "Belum digunakan" : (!this->status ? "Sudah digunakan" : "Dinonaktifkan")) << endl;
    cout << "ABILITY  \t: memilih dua pemain yang akan menukarkan masing-masing satu kartu secara acak" << endl;
}

int Swap::inputPlayerToSwap(Game &game, int currentPlayerNum, int alreadySelectedPlayerNum, string outputMsg)
{
    int playerOption, playerNumber;
    vector<int> playerNumsTemp;
    int playerCount = game.getPlayerCount();
    // bool valid = false;
    bool exceptionCaught;
    IOHandler<int> optionIO;

    do
    {
        try
        {
            cout << outputMsg << endl;
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

            playerOption = optionIO.getInputInAccepted(1, playerNumsTemp.size());
            playerNumber = playerNumsTemp[playerOption - 1];
            game.getPlayer(playerNumber); // Kalo ga berhasil akan throw PlayerNotExist
            exceptionCaught = false;
        }
        catch (PlayerNotExist &e)
        {
            cout << "Pemain tidak ditemukan. Ulangi!" << endl;
            playerNumsTemp.clear();
            exceptionCaught = true;
        }

    } while (exceptionCaught);

    return playerNumber;
}

void Swap::swapCardAtIdx(Game &game, int playerNum1, int playerNum2, int idx1, int idx2)
{
    // Prekondisi: idx1 dan idx2 valid
    Player &player1 = game.getPlayer(playerNum1);
    Player &player2 = game.getPlayer(playerNum2);
    MainCard temp = player1.getCard(idx1 - 1);
    player1.setCard(idx1 - 1, player2.getCard(idx2 - 1));
    player2.setCard(idx2 - 1, temp);
}