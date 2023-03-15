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
   IOHandler<int> intIO;
   
   Player& curPlayer=game.getPlayerInTurn();
   vector<MainCard> hand=curPlayer.getInventoryCards();
   MainCard cur=game.getTable().getCard(0);
   int curColor=cur.getColor();
   int punya=hand.size();
   int tableSize=game.getTable().getInventoryCards().size();

   bool submitted=false;

   cout<< "Pilih kartu yang ingin anda keluarkan: "<<endl;
	curPlayer.printCards();
   curPlayer.printCardsSpecifier();

   while (!submitted)
   {
      cout<<"Pilih kartu yang anda ingin berikan: ";
      pilihan=intIO.getInput();
      pilihan--;
      
      if(pilihan<punya && pilihan>=0 && (hand[pilihan].getColor()==curColor||tableSize==0)) {
         curPlayer.returnOneCardToDeck(game.getTable(),pilihan);
         submitted=true;
      }
      else{
         cout<<"Kartu tidak valid. Mohon ulangi."<<endl;
      }
                
   }
}

void Action::cangkul(Game& game, int color)
{
   IOHandler<string> stringIO;
   stringIO.addAccepted("YA");
   stringIO.addAccepted("TIDAK");

   Player& curPlayer=game.getPlayerInTurn();
   curPlayer.printCards();
   cout<<"Anda tidak punya kartu yang sesuai :("<<endl;

   while(!curPlayer.isColorExists(color) && curPlayer.getPlayerStatus())
   {
      cout<<"Ingin mencangkul? (YA/TIDAK)"<<endl;
      string input;
      input = stringIO.getInputInAccepted();
      if(input=="YA")
      {
         curPlayer.takeCardFromDeck(game.getDeck(),1);
         curPlayer.printCards();
      }
      else if(input=="TIDAK")
      {
         cout<<"Yah, sayang sekali :<< Anda keluar dari permainan."<<endl;
         curPlayer.setPlayerStatus(false);
      }
   }
}
