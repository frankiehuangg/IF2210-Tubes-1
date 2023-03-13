#ifndef _GAME_H_
#define _GAME_H_

#include "Player.hpp"
#include "Table.hpp"
#include "Deck.hpp"

class AbilityCard;

class Game {
protected:
	int round;
	int point;
	int turn;

	const int PLAYER_AMOUNT;
	const int WIN_POINT;

	vector<Player> players;
	Table table;
	Deck deck;

public:
	Game(int, int, int, int, int);

	void checkPlayerNameExist(string);

	/***** Getter & Setter *****/
	// Dipanggil pada akhir ronde ke-6 melalui metode givePoint, kembalikan nilai point
	int getTurn() const;

	int getPoint() const;
	// Dipanggil pada awal ronde ke-1, buat point menjadi 64
	void setPoint(int);

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
