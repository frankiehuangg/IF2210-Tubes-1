#ifndef _GAME_H_
#define _GAME_H_

#include "Player.hpp"
#include "Table.hpp"
#include "Deck.hpp"

class AbilityCard;

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

	void checkPlayerNameExist(string);

	int getPlayerCount() const;

	Player& getPlayer();

	Player& getPlayer(int);

	Player& getPlayer(string);

	Table& getTable();

	Deck& getDeck();

	bool gameOver();

	virtual void newShuffle() = 0;

	virtual void newRound() = 0;
};

#endif
