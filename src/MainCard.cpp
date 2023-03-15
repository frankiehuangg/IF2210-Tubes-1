#include "header/MainCard.hpp"

#define C00 "\x1B[0m"
#define C01 "\x1B[31m"
#define C02 "\033[0;33m"
#define C03 "\x1B[32m"
#define C04 "\x1B[34m"
#define C05 "\x1b[38;5;238m"

/* Constructor & destructor */
MainCard::MainCard(int val1, int val2)
{
    this->card.first = val1;
    this->card.second = val2;
}

/***** Getter & Setter *****/
// Number - Assumption: First element of the pair
int MainCard::getNumber() const
{
    return this->card.first;
}
void MainCard::setNumber(int number)
{
    this->card.first = number;
}

// Color - Assumption: Second element of the pair
int MainCard::getColor() const
{
    return this->card.second;
}
void MainCard::setColor(int color)
{
    this->card.second = color;
}

/***** Print *****/
// Print card number and color, ends with endl
void MainCard::printCard()
{
    std::cout << this->card.first << "(" << this->card.second << ")" << endl;
}

/***** Comparison *****/
bool operator< (const MainCard m1, const MainCard m2)
{
	return m1.getValue() < m2.getValue();
}

// Cek apakah nilai kartu < kartu lain
bool MainCard::operator<(Comparable &other)
{
    // Not sure yet
    return this->value < other.getValue();
}

// Cek apakah nilai kartu > kartu lain
bool MainCard::operator>(Comparable &other)
{
    // Not sure yet
    return this->value > other.getValue();
}

// Cek apakah nilai kartu = kartu lain
bool MainCard::operator==(Comparable &other)
{
    // Not sure yet
    return this->value == other.getValue();
}

ostream& operator<< (ostream& os, const vector<MainCard>& cards)
{
	string print[11][cards.size()];

	char line[100];

	int length = cards.size();

	for (int i = 0; i < length; i++)
	{
		FILE *fin = fopen("src/ascii/cards.txt", "r");

		int line_num = (cards[i].getNumber() - 1) * 11;

		int num = 0;
		while (num < line_num)
		{
			if (fgets(line, sizeof(line), fin) == NULL)
				cout << "ERROR : error occured when opening file" << endl;
			num++;
		}

		for (int j = 0; j < 11; j++)
		{
			if (fgets(line, sizeof(line), fin) == NULL)
				cout << "ERROR: error occured when opening file" << endl;
			print[j][i] = line;
		}
	}

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (cards[j].getColor() == 0)
				os << C01 << print[i][j].erase(print[i][j].length()-1) << " ";
			else if (cards[j].getColor() == 1)
				os << C02 << print[i][j].erase(print[i][j].length()-1) << " ";
			else if (cards[j].getColor() == 2)
				os << C03 << print[i][j].erase(print[i][j].length()-1) << " ";
			else
				os << C04 << print[i][j].erase(print[i][j].length()-1) << " ";
		}
		os << endl;
	}

	os << C00;

	return os;
}