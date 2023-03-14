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

// Submit a card to table
void Action::choose(Game& game)
{
   int pilihan;
   Player& curPlayer=game.getPlayer(game.getTurn()+1);
   vector<MainCard> hand=curPlayer.getInventoryCards();
   MainCard cur=game.getTable().getCard(0);
   int curColor=cur.getColor();
   int punya=hand.size();

   bool submitted=false;

   while (!submitted){
      cout<<"Pilih kartu yang anda ingin berikan: ";
      cin>>pilihan;
      
      if(pilihan<punya && pilihan>=0 && hand[pilihan].getColor()==curColor) {
         curPlayer.returnOneCardToDeck(game.getTable(),pilihan);
         submitted=true;
         cout<<"test";
      }
      else{
         cout<<"Kartu tidak valid. Mohon ulangi."<<endl;
      }
                
   }
}