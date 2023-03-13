#include <iostream>
#include "header/Poker.hpp"

Poker::Poker() : Game(0, 64, 0, 7, 1<<31), ROUND_AMOUNT(6)
{
	this->shuffle = 0;

	// Create player
	int i = 0;
	while (i < this->PLAYER_AMOUNT)
	{
		bool exception_caught = true;

		try
		{
			string name; cin >> name;

			checkPlayerNameExist(name);

			Player p(name, i+1);

			this->players.push_back(p);

			exception_caught = false;
		}
		catch (CreatePlayerFailed e)
		{
			cout << e.printError() << endl;
		}

		if (!exception_caught)
			i++;
	}
}

void Poker::roundRobin()
{
	this->players.push_back(this->players[0]);
	this->players.erase(this->players.begin());
}

void Poker::newShuffle()
{
	setPoint(64);

	for (int i = 0; i < this->ROUND_AMOUNT; i++)
	{
		newRound();
		this->round++;
	}

	Player& winner = this->players[0];
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

void Poker::newRound()
{
	this->turn = 0;

	// Ronde sebanyak pemain
	while (turn < this->PLAYER_AMOUNT)
	{
		// Ronde 1, pemain mendapatkan 2 MainCard dari Deck
		if (round == 0)
		{
			// Cek apakah pemain sudah mempunyai kartu, jika iya pindahkan ke deck
			if (!this->players[turn].isInventoryEmpty())
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
		if (round == 1)
		{
			/* tar buka comment tapi gtau salahnya apa
			// Cek apakah pemain sudah mempunyai ability card, jika iya pindahkan ke deck
			if (this->players[turn].doesAbilityCardExist())
				for (int i = 0; i < this->PLAYER_AMOUNT; i++)
					this->players[i].returnAbilityToDeck(this->deck);

			// Acak kartu ability
			this->deck.shuffleAbilityCards();

			// Ambil ability card dari pemain
			for (int i = 0; i < this->PLAYER_AMOUNT; i++)
				this->players[i].takeAbilityFromDeck(this->deck);
			*/
		}

		this->table.printCards();

		this->players[turn].printCards();

		// Ambil aksi pemain
		this->players[turn].doAction(*this);

		// Buka 1 kartu di table
		if (turn > 0)
			this->table.openCard();

		// Acak pemain dengan round robin
		roundRobin();
		
		this->turn++;
	}
}
