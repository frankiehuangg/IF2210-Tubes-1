#include "header/Ability_ReRoll.hpp"
#include "header/Game.hpp"

ReRoll::ReRoll()
{
	type = "RE-ROLL";
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
		Player &player = game.getPlayer();
		Deck &deck = game.getDeck();

		// move to deck
		vector<MainCard> vec = player - 2;
		deck + vec;

		// take from deck
		player.takeCardFromDeck(deck, 2);
	}
}

/***** Print card *****/
// Print card info and status
void ReRoll::printCard()
{
	std::cout << "NAME     : Re-Roll" << std::endl;
	std::cout << "STATUS   : " << (this->status && !this->isdisabled ? " Belum digunakan" : (!this->status ? " Sudah digunakan" : " Dinonaktifkan")) << std::endl;
	std::cout << "ABILITY  : Membuang kedua kartu yang ada di tangannya dan mengambil ulang dua kartu baru dari deck" << std::endl;
}
