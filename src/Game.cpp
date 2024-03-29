#include <iostream>
#include <limits>
#include "header/Game.hpp"

Game::Game(int round, int turn, long long point, int PLAYER_AMOUNT, long long WIN_POINT) : PLAYER_AMOUNT(PLAYER_AMOUNT), WIN_POINT(WIN_POINT)
{
	this->round = round;
	this->turn = turn;
	this->point = point;
}

void Game::playerInit()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// Create player
	int i = 0;
	while (i < this->PLAYER_AMOUNT)
	{
		bool exception_caught = true;

		try
		{
			cout << "Masukkan nama pemain ke-" << i + 1 << ": ";
			string name; getline(cin, name);

			checkPlayerNameExist(name);

			Player p(name, i + 1);

			this->players.push_back(p);

			exception_caught = false;
		}
		catch (CreatePlayerFailed &e)
		{
			cout << e.printError() << endl;
		}
		catch (PlayerNameInvalid &e)
		{
			cout << e.printError() << endl;
		}

		if (!exception_caught)
			i++;
	}
}

void Game::checkPlayerNameExist(string name)
{
	if (name == "")
		throw PlayerNameInvalid();
	
	int size = players.size();
	for (int i = 0; i < size; i++)
	{
		if (this->players[i].getPlayerName() == name)
			throw CreatePlayerFailed();
	}
}

int Game::getTurn() const
{
	return this->turn;
}

void Game::setTurn(int trn)
{
	this->turn=trn;
}

int Game::getRound() const
{
	return this->round;
}

long long Game::getPoint() const
{
	return this->point;
}

void Game::setPoint(long long point)
{
	this->point = point;
}

int Game::getPlayerCount() const
{
	return this->PLAYER_AMOUNT;
}

Player& Game::getPlayer()
{
	return this->players[0];
}

Player& Game::getPlayerInTurn()
{
	return this->players[this->turn];
}

Player& Game::getPlayerInTurn(int index)
{
	return this->players[index];
}

Player& Game::getPlayer(int number)
{
	int players_size = this->players.size();
	for (int i = 0; i < players_size; i++)
		if (this->players[i].getPlayerNumber() == number)
			return this->players[i];

	throw PlayerNotExist();
}

Player& Game::getPlayer(string name)
{
	for (int i = 0; i < this->PLAYER_AMOUNT; i++)
		if (this->players[i].getPlayerName() == name)
			return this->players[i];

	throw PlayerNotExist();
}
void Game::printPlayerTurn()
{
	cout<<"Current round's turn : ";
	for (int i = 0; i < this->PLAYER_AMOUNT; i++)
		cout<<this->players[i].getPlayerNumber()<<" ";
	cout<<endl;
}

void Game::setPlayerTurn(vector<Player> curTurn)
{
	this->players.clear();
	for(unsigned i=0; i<curTurn.size(); i++)
	{
		this->players.push_back(curTurn[i]);
	}
}


Table& Game::getTable()
{
	return this->table;
}

Deck& Game::getDeck()
{
	return this->deck;
}

void Game::startGame()
{
	newShuffle();
}
