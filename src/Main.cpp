#include <ostream>
#include "header/Poker.hpp"

#define C00 "\x1B[0m"
#define C01 "\x1B[31m"
#define C02 "\033[0;33m"
#define C03 "\x1B[32m"
#define C04 "\x1B[34m"
#define C05 "\x1b[38;5;238m"

ostream& operator<<(ostream& os, vector<MainCard>& m)
{
	string print[11][m.size()];

	char line[100];

	for (int i = 0; i < m.size(); i++)
	{
		FILE *fin = fopen("src/ascii/cards.txt", "r");

		int line_num = (m[i].getNumber() - 1) * 11;

		int num = 0;
		while (num < line_num)
		{
			if(fgets(line, sizeof(line), fin)==NULL){
				cout<<"ERROR : error occured when opening file"<<endl;
			}
			num++;
		}

		for (int j = 0; j < 11; j++)
		{
			if(fgets(line, sizeof(line), fin)==NULL){
				cout<<"ERROR : error occured when opening file"<<endl;
			}
			print[j][i] = line;
		}
	}

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < m.size(); j++)
		{
			if (m[j].getColor() == 0)
				os << C01 << print[i][j].erase(print[i][j].length()-1) << " ";
			else if (m[j].getColor() == 1)
				os << C02 << print[i][j].erase(print[i][j].length()-1) << " ";
			else if (m[j].getColor() == 2)
				os << C03 << print[i][j].erase(print[i][j].length()-1) << " ";
			else
				os << C04 << print[i][j].erase(print[i][j].length()-1) << " ";
		}
		os << endl;
	}

	os << C00;

	return os;
}

int main()
{
	vector<MainCard> red, yellow, green, blue;

	for (int i = 1; i < 14; i++)
	{
		MainCard tr(i, 0); red.push_back(tr);
		MainCard ty(i, 1); yellow.push_back(ty);
		MainCard tg(i, 2); green.push_back(tg);
		MainCard tb(i, 3); blue.push_back(tb);
	}

	cout << red << endl;
	cout << yellow << endl;
	cout << green << endl;
	cout << blue << endl;

	Table table;
	cout << table << endl;

	return 0;

	int input;

	cout << "Selamat datang di Kerajaan Permen!" << endl;
	cout << "Silahkan memilih permainan: " << endl;
	cout << "1. Poker" << endl;
	cout << "2. UNO" << endl;
	cout << "Pilihan: "; cin >> input;

	if (input == 1)
	{
		// Poker p;
		// p.startGame();
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
