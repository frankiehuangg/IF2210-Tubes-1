#ifndef _GAME_H_
#define _GAME_H_

#include "Table.hpp"
#include "Deck.hpp"
#include "Player.hpp"

class Game {
protected:
	int round;
	int turn;
	long long point;

	const int PLAYER_AMOUNT;
	const int WIN_POINT;

	vector<Player> players;
	Table table;
	Deck deck;

public:
	/***** Constructor *****/
	/* Game constructor
	 * @param int round				The amount of round in a shuffle
	 * @param int turn				The starting player turn
	 * @param long long point		Current point in game
	 * @param int PLAYER_AMOUNT		The amount of player in the game
	 * @param long long WIN_POINT	The amount of point needed to win the game */
	Game(int, int, long long, int, long long);

	
	/***** Exception Handling *****/
	/* Check whether player name already exist in vector of players
	 * @param string name		The string to be checked */
	void checkPlayerNameExist(string);

	/***** Getter & Setter *****/
	/* Returns the value of turn */
	int getTurn() const;

	/* Returns the value of round */
	int getRound() const;

	/* Returns the current point in game */
	long long getPoint() const;

	/* Set the current point in game 
	 * @int point		New point value */
	void setPoint(long long);

	/* Returns the amount of player */
	int getPlayerCount() const;

	/* Returns the first player in the vector */
	Player& getPlayer();

	/* Returns a player with the corresponding name
	 * @param string name	Player name */
	Player& getPlayer(string);

	/* Returns a player with the corresponding ID
	 * @param int number	Player number */ 
	Player& getPlayer(int);

	/* Returns the table */
	Table& getTable();

	/* Returns the deck */
	Deck& getDeck();

	/* Check whether the game is over */
	virtual bool gameOver()=0;

	/* Starts the game */
	void startGame();

	/* Starts a new shuffle */
	virtual void newShuffle() = 0;
};

#endif
