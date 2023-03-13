#include <ostream>
#include "header/Poker.hpp"

int main()
{
	int input;

	cout << "Selamat datang di Kerajaan Permen!" << endl;
	cout << "Silahkan memilih permainan: " << endl;
	cout << "1. Poker" << endl;
	cout << "2. UNO" << endl;
	cout << "Pilihan: "; cin >> input;

	if (input == 1)
	{
		Poker p;
		p.startGame();
	}
	else if (input == 2)
	{
		// UNO u;
		// u.startGame();
	}
	else
	{
		cout << "Input tidak valid!" << endl;
	}
}
