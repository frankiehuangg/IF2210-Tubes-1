#ifndef _POKER_HPP_
#define _POKER_HPP_

class Poker;

#include <vector>
#include <stdlib.h>
#include "Exception.hpp"
#include "Table.hpp"
#include "Game.hpp"

using namespace std;

class Poker : public Game {
private:
	int shuffle;

	const int ROUND_AMOUNT;

public:

	/***** Constructor dan destructor *****/
	/* Poker constructor */
	Poker();
	
	/* Shuffles the vector of players using RoundRobin */
	void roundRobin();

	/* Starts a new shuffle instance */
	void newShuffle();

	/* Starts a new round instance */
	void newRound();
};

#endif
