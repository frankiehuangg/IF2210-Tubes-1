#ifndef _COMBO_HPP_
#define _COMBO_HPP_

#include "Comparable.hpp"
#include "Player.hpp"
#include "Table.hpp"

class Combo : public Comparable {
public:
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
};

#endif
