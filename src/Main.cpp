#include <ostream>
#include "header/Poker.hpp"
#include "header/Cangkul.hpp"
#include "header/Combo_Calculator.hpp"

int main()
{
	int input;
	IOHandler<int> intIO;
	cout << "Selamat datang di Kerajaan Permen!" << endl;
	cout << "Silahkan memilih permainan: " << endl;
	cout << "1. Poker" << endl;
	cout << "2. Cangkul" << endl;
	cout << "3. Combo Calculator" << endl;
	input=intIO.getInputInAccepted(1,3);
	if (input == 1)
	{
		Poker p;
		p.startGame();
	}
	else if (input == 2)
	{
		Cangkul c;
		c.startGame();
	}
	else if (input == 3){
		ComboCalculator cc;
		cc.start();
	}
	else
	{
		cout << "Input tidak valid!" << endl;
	}
}
