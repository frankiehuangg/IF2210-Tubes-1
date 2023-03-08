#include "header/Action.hpp"
#include <iostream>
using namespace std;

// End player turn (No implementation)
void Action::actionDoNext(){}

// Double the value point in Game
void actionDoDouble(const Game& game){
   game.setPoint(game.getPoint()*2);
}

// Half the value point in Game
void actionDoHalf(const Game&){
   game.setPoint(game.getPoint()/2);
}
