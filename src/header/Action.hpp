#ifndef _ACTION_HPP_
#define _ACTION_HPP_

#include "Game.hpp"
#include "Poker.hpp"

class Action {
public:
	// End player turn (No implementation)
	void actionDoNext();

	// Double the value point in Game
	void actionDoDouble(const Game&);

	// Half the value point in Game
	void actionDoHalf(const Game&);
};

#endif
