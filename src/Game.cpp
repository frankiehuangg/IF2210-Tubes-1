#include "header/Game.hpp"

Game::Game(int round, int turn, long long point, int PLAYER_AMOUNT, long long WIN_POINT) : PLAYER_AMOUNT(PLAYER_AMOUNT), WIN_POINT(WIN_POINT)
{
	this->round = round;
	this->turn = turn;
	this->point = point;
}

void Game::checkPlayerNameExist(string name)
{
	for (unsigned i = 0; i < this->players.size(); i++)
		if (this->players[i].getPlayerName() == name)
			throw CreatePlayerFailed();
}

int Game::getTurn() const
{
	return this->turn;
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

Player& Game::getPlayer(int number)
{
	for (int i = 0; i < this->PLAYER_AMOUNT; i++)
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

Table& Game::getTable()
{
	return this->table;
}

Deck& Game::getDeck()
{
	return this->deck;
}

bool Game::gameOver()
{
	for (int i = 0; i < this->PLAYER_AMOUNT; i++)
		if (this->players[i].getPlayerPoint() > (1 << 31))
			return true;

	return false;
}

void Game::startGame()
{
	newShuffle();
}
