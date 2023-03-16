#include <iostream>
#include <limits>
#include "header/Poker.hpp"

Poker::Poker() : Game(0, 64, 0, 7, 1LL << 31), ROUND_AMOUNT(6), combos(PLAYER_AMOUNT)
{

	this->shuffle = 0;
	playerInit();
}

void Poker::roundRobin()
{
	Player temp = this->players[0];
	this->players.erase(this->players.begin());
	this->players.push_back(temp);
}

void Poker::newShuffle()
{
	setPoint(64);
	this->round = 0;

	table.setOpened(0);

	for (int i = 0; i < this->ROUND_AMOUNT; i++)
	{
		// Ronde 1, pemain mendapatkan 2 MainCard dari Deck
		if (this->round == 0)
		{
			// Cek apakah pemain sudah mempunyai kartu, jika iya pindahkan ke deck
			if (!this->players[round].isInventoryEmpty())
			{
				for (int i = 0; i < this->PLAYER_AMOUNT; i++)
				{
					this->players[i].returnCardToDeck(this->deck);
				}
			}

			// Cek apakah table sudah mempunyai kartu, jika iya pindahkan ke deck
			if (!this->table.isInventoryEmpty())
				this->table.returnCardToDeck(this->deck);

			bool repeat;
			do
			{
				repeat = false;
				try
				{
					cout << "Pilih input deck: " << endl;
					cout << "1. Acak" << endl;
					cout << "2. Dari file" << endl;

					IOHandler<int> intIO;
					int input = intIO.getInputInAccepted(1, 2);

					if (input == 1)
					{
						this->deck.shuffleMainCards();
					}
					else
					{
						this->deck.getDeckFromInput();
					}
				}
				catch (InvalidFile &err)
				{
					repeat = true;
				}
			} while (repeat);

			// Ambil 2 kartu dari deck ke pemain
			for (int i = 0; i < this->PLAYER_AMOUNT; i++)
				this->players[i % this->PLAYER_AMOUNT].takeCardFromDeck(this->deck, 2);

			// Taruh 5 kartu dari deck ke table
			this->table.takeCardFromDeck(this->deck, 5);
		}

		// Ronde 2, pemain dapat menggunakan abilityCard
		if (this->round == 1)
		{
			// Cek apakah pemain sudah mempunyai ability card, jika iya pindahkan ke deck
			if (this->players[round].doesAbilityCardExist())
				for (int i = 0; i < this->PLAYER_AMOUNT; i++)
					this->players[i].returnAbilityToDeck(this->deck);

			// Acak kartu ability
			this->deck.shuffleAbilityCards();

			// Ambil ability card dari pemain
			for (int i = 0; i < this->PLAYER_AMOUNT; i++)
				this->players[i].takeAbilityFromDeck(this->deck);
		}
		// Buka 1 kartu di table
		if (this->round > 0)
			this->table.openCard();

		newRound();
		roundRobin();

		this->round++;
	}

	// Calculate winning combo
	for (int i = 0; i < this->PLAYER_AMOUNT; i++)
	{
		Player &player = this->players[i];
		this->combos[i] = Combo(player, this->table);
		// player.printInfo();
		cout << "Player " << player.getPlayerName() << " mendapatkan combo ";
		cout << "⚡" << this->combos[i].what() << "⚡" << '\n';
		cout << this->combos[i];
	}

	// int winnerID = maxElmtidx(this->combos);
	int winnerID = 0;
	for (int i = 1; i < this->PLAYER_AMOUNT; i++)
	{
		if (this->combos[i] > this->combos[winnerID])
		{
			winnerID = i;
		}
	}

	this->players[winnerID].addPlayerPoint(this->point);

	if (!gameOver())
	{
		cout << "Pemain " << this->players[winnerID].getPlayerName() << " mendapatkan poin " << this->point << endl;
		this->shuffle++;
		newShuffle();
	}
	else
	{
		cout << "Pemain " << this->players[winnerID].getPlayerName() << " memenangkan permainan dengan poin " << this->players[winnerID].getPlayerPoint() << "!" << endl;
	}
}

bool Poker::gameOver()
{
	for (int i = 0; i < this->PLAYER_AMOUNT; i++)
		if (this->players[i].getPlayerPoint() > this->WIN_POINT)
			return true;

	return false;
}

void Poker::newRound()
{
	this->turn = 0;

	// Ronde sebanyak pemain
	while (this->turn < this->PLAYER_AMOUNT)
	{
		system("clear");

		cout << "Round\t\t: " << getRound() + 1 << endl;

		cout << "Game point\t: " << this->point << endl;

		cout << "Table cards" << endl;

		this->table.printCards();

		players[turn].printInfo();

		cout << "Player cards" << endl;
		this->players[turn].printCards();

		// Ambil aksi pemain
		this->players[turn].doAction(*this);

		this->turn++;

		cout << "Press any key to continue..." << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
	}
}
