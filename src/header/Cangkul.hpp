#ifndef _CANGKUL_HPP_
#define _CANGKUL_HPP_

class Cangkul;

#include <vector>
#include <stdlib.h>
#include "Exception.hpp"
#include "Table.hpp"
#include "Game.hpp"

using namespace std;

class Cangkul : public Game {
private:
	int shuffle;

	Table buangan;
	const int ROUND_AMOUNT;

public:

	/***** Constructor dan destructor *****/
	/* Poker constructor */
	Cangkul();

	/* Check whether the game is over */
	bool gameOver();

	/* Starts a new shuffle instance */
	void newShuffle();

	/* Starts a new round instance */
	void newRound();
};

#endif
