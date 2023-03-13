#ifndef _GAME_H_
#define _GAME_H_

#include "Table.hpp"
#include "Deck.hpp"
#include "Player.hpp"

class Game {
protected:
	int round;
	long long point;
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

	Player& getPlayer(string);

	Player& getPlayer(int);

	Table& getTable();

	Deck& getDeck();

	bool gameOver();

	void startGame();

	virtual void newShuffle() = 0;

	virtual void newRound() = 0;
};

#endif
