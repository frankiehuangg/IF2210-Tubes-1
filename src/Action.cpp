#include "header/Action.hpp"
#include <iostream>
using namespace std;
#include "header/Game.hpp"

// End player turn (No implementation)
void Action::actionDoNext(){}

// Double the value point in Game
void Action::actionDoDouble(Game& game)
{
   game.setPoint(game.getPoint() * 2);
}

// Half the value point in Game
void Action::actionDoHalf(Game& game)
{
   game.setPoint(max(game.getPoint()/2,1LL));
}
