#include <iostream>
#include "header/Cangkul.hpp"

Cangkul::Cangkul() : Game(0, 64, 0, 4, 1 << 31), ROUND_AMOUNT(6)
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
	int size=this->table.getInventoryCards().size();
	int iterator=size-1;
	map<int,int> rank;

	for(int i=this->PLAYER_AMOUNT-1; i>=0; i--)
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
		temp.push_back(this->getPlayer(it.second));

	}

	this->players.clear();
	int temp_size = temp.size();
	for(int i=0; i<temp_size; i++)
		this->players.push_back(temp[i]);
	this->table.returnCardToDeck(dump);

}

bool Cangkul::dumpManage()
{
	if(this->deck.isInventoryEmpty()) 
    {
    	if(this->dump.isInventoryEmpty())
         {
			return false;
         }
         dump.returnCardToDeck(this->deck);
    }
	return true;
}

void Cangkul::newShuffle()
{
	this->table.setOpened(10);
	this->dump.setOpened(1);
	this->deck.shuffleMainCards();

	// bagikan kartu ke pemain
	for (int i = 0; i < this->PLAYER_AMOUNT*4; i++)
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
	gameWinner();
}

void Cangkul::newRound()
{
	this->printPlayerTurn();
	this->turn = 0;
	if(this->table.isInventoryEmpty()){
		cout << "Giliran pemain dengan ID " << players[turn].getPlayerNumber() << " dengan nama " << players[turn].getPlayerName() << endl;

		this->players[turn].getPlayerAction().choose((*this));

		this->turn++;
	}

	int curColor=table.getCard(0).getColor();

	// Giliran sebanyak pemain
	while (this->turn < this->PLAYER_AMOUNT && !gameOver())
	{
		cout << "Giliran pemain dengan ID " << players[turn].getPlayerNumber() << " dengan nama " << players[turn].getPlayerName() << endl;

		this->table.printCards();

		if(players[turn].isColorExists(curColor))
		{
			this->players[turn].getPlayerAction().choose((*this));
		}
		else
		{
			this->players[turn].getPlayerAction().cangkul((*this),curColor,this->dump);
			if(this->players[turn].getPlayerStatus())
				this->players[turn].getPlayerAction().choose((*this));
		}

		this->turn++;
	}
	this->roundManage();
}

bool Cangkul::gameOver()
{
	if (this->PLAYER_AMOUNT<=1) return true;

	int count=0;
	for (int i = 0; i < this->PLAYER_AMOUNT; i++)
		if (this->players[i].getInventoryCards().size() == 0 && this->players[i].getPlayerStatus())
			count++;

	return count>=1;
}

/* Check who won the game  */
void Cangkul::gameWinner()
{
	if (this->PLAYER_AMOUNT==1)
	{
		Player win= players[0];
		cout<<"Player "<<win.getPlayerName()<<" dengan ID "<<win.getPlayerNumber()<<" memenangkan permainan!"<<endl;
	}

	for (int i = 0; i < this->PLAYER_AMOUNT; i++)
		if (this->players[i].getInventoryCards().size() == 0 && this->players[i].getPlayerStatus())
		{
			Player win= players[i];
			cout<<"Player "<<win.getPlayerName()<<" dengan ID "<<win.getPlayerNumber()<<" memenangkan permainan!"<<endl;
		}
}
