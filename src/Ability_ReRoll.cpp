#include "header/Ability_ReRoll.hpp"

// Buang 2 kartu milik player sekarang, ambil ulang kartu dari deck
void useAbility(const Game &game)
{
	// gimana tau player sekarang... ? help
	// di sini dianggap ada penunjuk ke player sekarang
	// anggap sj variabel currentPlayer

	game.players[currentPlayer] - 2;		   // discard 2 cards
	vector<MainCard> newCards = game.deck - 2; // grab 2 new cards from deck
	game.players[currentPlayer] + newCards;
}

/***** Print card *****/
// Print card info and status, if round = 1 print "NOT AVAILABLE or sum other shit idk"
void printCard()
{
	// tidak bisa cek round, tdk ada passing parameter :(
	// MUNGKIN klo butuh jadi void printCard(const Game&) ?
	// jadi implemennya
	/*
	if(game.round==1){
		cout<<"NOT AVAILABLE"<<endl;
	}
	else{
		cout<<"Buang 2 kartu milik player sekarang, ambil ulang kartu dari deck"<<endl;
	}
	*/
}