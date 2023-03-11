#include <iostream>
#include "header/Poker.hpp"

Poker::Poker() : ROUND_AMOUNT(6), PLAYER_AMOUNT(7)
{
	this->shuffle = 0;
	this->round = 0;
	this->point = 64;

	// Create player
	int i = 0;
	while (i < this->PLAYER_AMOUNT)
	{
		bool exception_caught = true;

		try
		{
			string name; cin >> name;

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

void Poker::checkPlayerNameExist(string name)
{
	for (int i = 0; i < this->players.size(); i++)
		if (this->players[i].getPlayerName() == name)
			throw CreatePlayerFailed();
}

int Poker::getPoint() const
{
	return this->point;
}

void Poker::setPoint()
{
	this->point = 64;
}

int Poker::getPlayerCount() const
{
	return this->PLAYER_AMOUNT;
}

Player& Poker::getPlayer(int number)
{
	for (int i = 0; i < this->PLAYER_AMOUNT; i++)
		if (this->players[i].getPlayerNumber() == number)
			return this->players[i];

	throw PlayerNotExist();
}

Player& Poker::getPlayer(string name)
{
	for (int i = 0; i < this->PLAYER_AMOUNT; i++)
		if (this->players[i].getPlayerName() == name)
			return this->players[i];

	throw PlayerNotExist();
}

bool Poker::gameOver()
{
	for (int i = 0; i < this->PLAYER_AMOUNT; i++)
		if (this->players[i].getPlayerPoint() > (1 << 31))
			return true;

	return false;
}

void Poker::roundRobin()
{
	this->players.push_back(this->players[0]);
	this->players.pop_back();
}

void Poker::newShuffle()
{
	setPoint();

	for (int i = 0; i < this->ROUND_AMOUNT; i++)
		newRound(i);

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

void Poker::newRound(int round)
{
	int turn = 0;

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
			// Cek apakah pemain sudah mempunyai ability card, jika iya pindahkan ke deck
			if (this->players[turn].doesAbilityCardExist())
				for (int i = 0; i < this->PLAYER_AMOUNT; i++)
					this->players[i].returnAbilityToDeck(this->deck);

			// Acak kartu ability
			this->deck.shuffleAbilityCards();

			// Ambil ability card dari pemain
			for (int i = 0; i < this->PLAYER_AMOUNT; i++)
				this->players[i].takeAbilityFromDeck(this->deck);
		}

		this->table.printCards();

		this->players[turn].printCards();

		// Ambil aksi pemain
		this->players[turn].doAction();

		// Buka 1 kartu di table
		if (turn > 0)
			this->table.openCard();

		// Acak pemain dengan round robin
		roundRobin();
		
		turn++;
	}
}
