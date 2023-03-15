#ifndef _ACTION_HPP_
#define _ACTION_HPP_

#include "Io_Handler.hpp"

class Inventory;
class Game;
class Cangkul;
class Action {
public:
	/* End current player's turn, no implementation */
	void actionDoNext();

	/* Double the current point value in Game
	 * @param Game& game	Current game */
	void actionDoDouble(Game&);

	/* Half the current point value in Game
	 * @param Game& game	Current game */
	void actionDoHalf(Game&);
	
	/* Choose card to submit to table
	 * @param Game& game	Current game */
	void choose(Game&);

	/* Do cangkul until found or gives up
	 * @param Game& game		Current game 
	 * @param int color		 	Color to search 
	 * @param Inventory& dump	Dump place */
	void cangkul(Cangkul&,int,Inventory&);
};

#endif
