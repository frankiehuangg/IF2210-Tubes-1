#include <iostream>
#include "header/Poker.hpp"

Poker::Poker() : Game(0, 64, 0, 7, 1 << 31), ROUND_AMOUNT(6)
{
	this->shuffle = 0;

	// Create player
	int i = 0;
	while (i < this->PLAYER_AMOUNT)
	{
		bool exception_caught = true;

		try
		{
			cout << "Masukkan nama pemain ke-" << i + 1 << ": ";
			string name;
			cin >> name;

			checkPlayerNameExist(name);

			Player p(name, i + 1);

			this->players.push_back(p);

			exception_caught = false;
		}
		catch (CreatePlayerFailed &e)
		{
			cout << e.printError() << endl;
		}

		if (!exception_caught)
			i++;
	}
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

			this->deck.shuffleMainCards();

			// Ambil 2 kartu dari deck ke pemain
			for (int i = 0; i < this->PLAYER_AMOUNT*2; i++)
				this->players[i % this->PLAYER_AMOUNT].takeCardFromDeck(this->deck, 1);

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

			// // Ambil ability card dari pemain
			// for (int i = 0; i < this->PLAYER_AMOUNT; i++)
			// 	this->players[i].takeAbilityFromDeck(this->deck);
		}
		// Buka 1 kartu di table
		if (this->round > 0)
			this->table.openCard();

		newRound();
		roundRobin();

		this->round++;
	}

	Player &winner = this->players[0];
	for (int i = 1; i < this->PLAYER_AMOUNT; i++)
		if (this->players[i] > winner)
			winner = this->players[i];

	winner.addPlayerPoint(this->point);

	if (!gameOver())
	{
		this->shuffle++;
		newShuffle();
	}
}

bool Poker::gameOver()
{
	for (int i = 0; i < this->PLAYER_AMOUNT; i++)
		if (this->players[i].getPlayerPoint() > (1 << 31))
			return true;

	return false;
}

void Poker::newRound()
{
	this->turn = 0;

	// Ronde sebanyak pemain
	while (this->turn < this->PLAYER_AMOUNT)
	{
		//system("clear");
		
		cout << "Round: " << getRound()+1 << endl;

		cout << "Giliran pemain dengan ID " << players[turn].getPlayerNumber() << " dengan nama " << players[turn].getPlayerName() << endl;

		cout << "Poin game sekarang: " << this->point << endl;

		this->table.printCards();

		this->players[turn].printCards();

		// Ambil aksi pemain
		this->players[turn].doAction(*this);

		this->turn++;
	}
}
