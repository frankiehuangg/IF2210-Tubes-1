#ifndef _GAME_H_
#define _GAME_H_

#include "Player.hpp"
#include "Deck.hpp"

class Game {
protected:
	int point;

	const int PLAYER_AMOUNT;
	const int WIN_POINT;

	vector<Player> players;
	Table table;
	Deck deck;

public:
	Game(int, int, int);

	virtual void checkPlayerNameExist(string) = 0;

	virtual int getPlayerCount() const = 0;

	virtual Player& getPlayer(int) = 0;

	virtual Player& getPlayer(string) = 0;

	virtual bool gameOver() = 0;

	virtual void newRound(int) = 0;
};

#endif
