#include "header/Action.hpp"
#include <iostream>
using namespace std;
#include "header/Game.hpp"

// End player turn (No implementation)
void Action::actionDoNext(){}

// Double the value point in Game
void actionDoDouble(Game& game)
{
   game.setPoint(game.getPoint() * 2);
}

// Half the value point in Game
void actionDoHalf(Game& game)
{
   game.setPoint(game.getPoint() / 2);
}
