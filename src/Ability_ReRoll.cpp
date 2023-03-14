#include "header/Ability_ReRoll.hpp"
#include "header/Game.hpp"

ReRoll::ReRoll(){
	type = "REROLL";
}

// Buang 2 kartu milik player sekarang, ambil ulang kartu dari deck
void ReRoll::useAbility(Game &game)
{
	if (!this->getStatus()) 
    {
        cout << "Oops, kartu ability ReRoll telah dimatikan sebelumnya :(" << endl
             << "Silahkan lakukan perintah lain.";
    }
	else
	{
		Player& player = game.getPlayer();
		Deck& deck = game.getDeck();

		// move to deck
		vector<MainCard> vec = player - 2;
		deck + vec;

		// take from deck
		player.takeCardFromDeck(deck,2);
	}
	
}

/***** Print card *****/
// Print card info and status, if round = 1 print "NOT AVAILABLE or sum other shit idk"
void ReRoll::printCard()
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
