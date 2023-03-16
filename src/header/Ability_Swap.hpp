#ifndef _ABILITY_SWAP_HPP_
#define _ABILITY_SWAP_HPP_

#include "AbilityCard.hpp"

class Swap : public AbilityCard {
public:
	Swap();

	/**** Use ability, different for each card *****/
	// Swap 1 kartu pemain lain dengan 1 kartu pemain lain
	// Minta input nama pemain yang ingin ditukar, lalu tanya kartu yang mana (1 atau 2)
	void useAbility(Game&);

	/***** Print card *****/
	// Print card info and status
	void printCard();

	/**** Some utility methods to help useAbility() ****/
	/* why public static? supaya bisa dipake dari kelas Switch tanpa membuat objek Swap, 
	karena basically switch = swap kedua kartu diri sendiri dengan satu pemain lain. DRY right? wkwk */

	/* Untuk mendapatkan input pemain yang akan di swap
	* @param Game &game							Game yang dimainkan
	* @param int currentPlayerNum				Nomor pemain yang in turn saat ini
	* @param int alreadySelectedPlayerNum		Nomor pemain yang sudah dipilih, agar tidak ditampilkan lagi (jika belum ada, masukan 0)
	* @param string outputMsg					Pesan yang akan ditampilkan, misalnya "Masukkan pemain lain yang akan ditukar" */
	static int inputPlayerToSwap(Game&, int, int, string);

	/* Untuk menukar kartu dua pemain pada index
	* @param Game& game			Game yang dimainkan
	* @param int playerNum1 	Nomor pemain pertama yang akan ditukar
	* @param int playerNum2		Nomor pemain kedua yang akan ditukar
	* @param int idx1			Indeks kartu pemain pertama yang akan ditukar (1 = kanan, 2 = kiri)
	* @param int idx2			Indeks kartu pemain pertama yang akan ditukar (1 = kanan, 2 = kiri) */	
	static void swapCardAtIdx(Game&, int, int, int, int);
};

#endif
