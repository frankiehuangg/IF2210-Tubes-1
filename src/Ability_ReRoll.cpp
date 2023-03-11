#include "header/Ability_ReRoll.hpp"

// Buang 2 kartu milik player sekarang, ambil ulang kartu dari deck
void useAbility(const Game &game)
{
	game.players[game.turn] - 2;		   // discard 2 cards
	vector<MainCard> newCards = game.deck - 2; // grab 2 new cards from deck
	game.players[game.turn] + newCards;
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
		cout << "NAME     : Re-Roll" << endl;
        cout << "STATUS   : " << this->status << endl;
        cout << "ABILITY  : Membuang kedua kartu yang ada di tangannya dan mengambil ulang dua kartu baru dari deck" << endl;
	*/
}