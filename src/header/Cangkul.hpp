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
	Table dump;
	const int ROUND_AMOUNT;

public:

	/***** Constructor dan destructor *****/
	/* Cangkul constructor */
	Cangkul();

	/* Determines the next round position */
	void roundManage();

	/* Manage the dump, return true if deck is cangkul-able */
	bool dumpManage();

	/* Check whether the game is over */
	bool gameOver();

	/* Announce who won the game  */
	void gameWinner();

	/* Starts a new shuffle instance */
	void newShuffle();

	/* Starts a new round instance */
	void newRound();
};

#endif
