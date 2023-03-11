#ifndef _COMBO_HPP_
#define _COMBO_HPP_

#include <map>
#include "Comparable.hpp"
#include "MainCard.hpp"
#include "Table.hpp"

class Combo : public Comparable {
public:
	/***** Constructor *****/
	// Inisialisasi map berisi combo-combo yang ada
	Combo();

	/****** Getter & Setter *****/
	float getValue() const;
	void setValue(float);

	/***** Comparison *****/
	// Implementasi combo pakai map
	// Cek apakah nilai kombo > kombo lain
	bool operator> (Comparable&);

	// Cek apakah nilai kombo < kombo lain
	bool operator< (Comparable&);

	// Cek apakah nilai kombo == kombo lain
	bool operator== (Comparable&);

private:
	map<vector<MainCard>, float> combo_list;
	vector<MainCard> cards;
};

#endif
