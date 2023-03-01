#ifndef _POKER_HPP_
#define _POKER_HPP_

#include <vector>
#include "Player.hpp"
#include "Table.hpp"
#include "Deck.hpp"

using namespace std;

class Poker {
protected:
	int shuffle;
	int round;
	int point;

	vector<Player> players;
	Table table;
	Deck deck;

public:

	/***** Constructor dan destructor *****/
	// Pada awal permainan, inisiasi 7 orang pemain dengan mengisialisasikan nilai players.
	Poker();

	/***** Getter & Setter *****/
	// Dipanggil pada akhir ronde ke-6 melalui metode givePoint, kembalikan nilai point
	int getPoint() const;

	// Dipanggil pada awal ronde ke-1, buat point menjadi 64
	void setPoint();

	/***** Fungsi Gameplay *****/
	// Cek apakah point > 2^32, jika iya maka kembalikan true
	bool gameOver();

	// Berikan point pada pemenang ronde
	void givePoint(Player&);

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
