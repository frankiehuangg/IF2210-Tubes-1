#include <iostream>
#include "header/Cangkul.hpp"

Cangkul::Cangkul() : Game(0, 64, 0, 2, 1 << 31), ROUND_AMOUNT(6)
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


void Cangkul::newShuffle()
{
	this->table.setOpened(4);
	this->buangan.setOpened(1);
	// bagikan kartu ke pemain
	for (int i = 0; i < this->PLAYER_AMOUNT*7; i++)
			this->players[i % this->PLAYER_AMOUNT].takeCardFromDeck(this->deck, 1);

	while(!gameOver()){
		if (this->round == 0)
		{
			//kita hanya bisa lihat kartu teratas
			

			//ambil satu card dari deck untuk pertama kali
			this->table.takeCardFromDeck(this->deck, 1);
		}
		
		newRound();

		this->round++;

	}
}

void Cangkul::newRound()
{
	this->turn = 0;
	if(this->table.isInventoryEmpty()){
		cout << "Giliran pemain dengan ID " << players[turn].getPlayerNumber() << " dengan nama " << players[turn].getPlayerName() << endl;

		cout<< "Pilih kartu yang ingin anda keluarkan: "<<endl;
		
		this->players[turn].printCards();	
	}
	// Giliran sebanyak pemain
	while (this->turn < this->PLAYER_AMOUNT)
	{

		cout << "Giliran pemain dengan ID " << players[turn].getPlayerNumber() << " dengan nama " << players[turn].getPlayerName() << endl;

		cout << "Poin game sekarang: " << this->point << endl;

		this->table.printCards();

		this->players[turn].printCards();

		// Ambil aksi pemain
		this->players[turn].doAction(*this);

		this->turn++;
	}
}

bool Cangkul::gameOver()
{
	int count=0;
	for (int i = 0; i < this->PLAYER_AMOUNT; i++)
		if (this->players[i].getPlayerPoint() > 0)
			count++;

	return count>1;
}
