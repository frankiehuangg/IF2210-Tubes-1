#ifndef _POKER_HPP_
#define _POKER_HPP_

class Poker;

#include <vector>
#include <stdlib.h>
#include "Exception.hpp"
#include "Table.hpp"
#include "Game.hpp"

using namespace std;

class Poker : public Game {
private:
	int shuffle;

	const int ROUND_AMOUNT;

public:

	/***** Constructor dan destructor *****/
	// Pada awal permainan, inisiasi 7 orang pemain dengan mengisialisasikan nilai players.
	Poker();
	
	void roundRobin();

	// Panggil ketika awal permainan atau ronde ke-6 sudah berakhir.
	// Pada fungsi, implementasikan sebagai berikut:
	// - Panggil setPoint
	// - Loop sebanyak 6 kali, lalu panggil newRound
	// - Hitung siapa pemenangnya
	// - Panggil givePoint dengan parameter player yang menang.
	// - cek apakah permainan telah berakhir dengan gameOver(). Jika permainan telah berakhir, maka objek akan didestruct.
	void newShuffle();

	// Dipanggil oleh newShuffle
	// Pada metode, implementasikan sebagai berikut:
	// - Pada awal fungsi, cetak kartu yang ada di table dan kartu yang ada di tangan pemain
	// - Tanyakan aksi pemain
	//
	// Selain itu, terdapat juga kondisional sebagai berikut:
	// - Awal ronde pertama: pemain mendapatkan 2 MainCard dari Deck
	// - Awal ronde kedua: pemain mendapatkan 1 AbilityCard dari Deck
	// - Akhir ronde pertama hingga kelima: 1 MainCard akan diletakkan pada Table

	void newRound();
};

#endif
