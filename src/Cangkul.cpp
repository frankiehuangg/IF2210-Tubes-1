#include <iostream>
#include "header/Cangkul.hpp"

/*
TO DO:
- refresh table tiap round
- game stop when theres winner
- saat deck kosong ambil dari buangan
- validasi input integer

*/

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

/* Determines the next round position */
void Cangkul::roundManage()
{
	int size=this->table.getAmount();
	int iterator=size-1;
	map<int,int> rank;

	for(int i=players.size()-1; i>=0; i--)
	{
		MainCard curCard=table.getCard(iterator);
		if(players[i].getPlayerStatus())
		{
			rank[curCard.getNumber()*-1]=players[i].getPlayerNumber();
			iterator--;
		}
	}
	vector<Player> temp;
	for(auto it:rank)
	{
		this->players.push_back(this->getPlayer(it.second));
	}

	this->players.clear();
	this->players=temp;


}


void Cangkul::newShuffle()
{
	this->table.setOpened(4);
	this->buangan.setOpened(1);
	// bagikan kartu ke pemain

	this->deck.shuffleMainCards();

	for (int i = 0; i < this->PLAYER_AMOUNT*2; i++)
			this->players[i % this->PLAYER_AMOUNT].takeCardFromDeck(this->deck, 1);

	while(!gameOver()){
		if (this->round == 0)
		{	
			//ambil satu card dari deck untuk ronde pertama
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

		this->players[turn].getPlayerAction().choose((*this));

		this->turn++;
	}

	int curColor=table.getCard(0).getColor();

	// Giliran sebanyak pemain
	while (this->turn < this->players.size())
	{
		cout << "Giliran pemain dengan ID " << players[turn].getPlayerNumber() << " dengan nama " << players[turn].getPlayerName() << endl;

		this->table.printCards();

		if(players[turn].isColorExists(curColor))
		{
			this->players[turn].getPlayerAction().choose((*this));
		}
		else
		{
			this->players[turn].getPlayerAction().cangkul((*this),curColor);
			if(this->players[turn].getPlayerStatus())
				this->players[turn].getPlayerAction().choose((*this));
		}

		this->turn++;
	}
	this->roundManage();
}

bool Cangkul::gameOver()
{
	if (this->players.size()<=1) return true;

	int count=0;
	for (int i = 0; i < this->PLAYER_AMOUNT; i++)
		if (this->players[i].getInventoryCards().size() == 0)
			count++;

	return count>=1;
}
