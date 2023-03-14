#include "header/Player.hpp"

Player::Player(string _name, int _number) : Inventory(2) {
    name = _name;
    number = _number;
    point = 0;

    ability = NULL;

    // Push dummmy elements for vector to allocate size beforehand
    MainCard dummy(-1, -1);
    cards.push_back(dummy);
    cards.push_back(dummy);

    // initialize Action;
}

Player::~Player() {
	delete ability;
}

int Player::getPlayerNumber() const {
    return number;
}

string Player::getPlayerName() const {
    return name;
}

int Player::getPlayerPoint() const {
    return point;
}

void Player::addPlayerPoint(long long additionalPoint) {
    point += additionalPoint;
}

bool Player::doesAbilityCardExist() const {
    return ability != NULL;
}

bool Player::getAbilityCardStatus() const {
    if(ability == NULL) throw NoAbilityAvailable();
    return ability->getStatus();
}

void Player::setAbilityCardStatus(bool status) {
    ability->setStatus(status);
}

void Player::returnAbilityToDeck() {
    ability->setStatus(true);
    ability = NULL;
}

void Player::takeAbilityFromDeck(Deck& deck) {
    ability = deck.takeAbilityFromDeck();
}

void Player::doAction(Game& game) {
    string input;
    bool invalidInput;
    do {
        invalidInput = false;
		cout << "Masukkan input pengguna: ";
        getline(cin, input);
        getchar(); // consume remaining \n in stream
        if (input == "NEXT") {
            cout << "Giliran dilanjut ke pemain selanjutnya.\n";
        }
        else if (input == "USE ABILITY") {
            try {
                useAbility(game);
            }
            catch (NoAbilityAvailable& err) {
                cout << err.what();
            }
        }
        else if (input == "DOUBLE") {
            playerAction.actionDoDouble(game);
        }
        else if (input == "HALF") {
            playerAction.actionDoHalf(game);
        }
        else {
            cout << "Sintaks input tidak valid, mohon ulangi!\n";
            invalidInput = true;
        }

    } while (invalidInput);
}

void Player::useAbility(Game& game) {
    if (ability == NULL) throw NoAbilityAvailable();
    else {
        ability->useAbility(game);
    }
}

ostream& operator<< (ostream& os, Player player)
{
	vector<MainCard> cards = player.getInventoryCards();

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

void Player::printCards() {
	cout << (*this);
}

bool Player::operator< (Comparable& other) {
    return point < other.getValue();
}

bool Player::operator> (Comparable& other) {
    return point > other.getValue();
}

bool Player::operator== (Comparable& other) {
    return point == other.getValue();
}
