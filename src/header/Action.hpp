#ifndef _ACTION_HPP_
#define _ACTION_HPP_

class Game;
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
};

#endif
