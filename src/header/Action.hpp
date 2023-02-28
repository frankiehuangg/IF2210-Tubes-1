#ifndef _ACTION_HPP_
#define _ACTION_HPP_

#include "Game.hpp"

class Action {
public:
	// End player turn
	virtual void actionDoNext() = 0;

	// Double the value point in Game
	virtual void actionDoDouble(const Game&) = 0;

	// Half the value point in Game
	virtual void actionDoHalf(const Game&) = 0;
};

#endif
