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

float Player::getValue() const {
    return point;
}

void Player::setValue(float _point) {
    point = _point;
}

int Player::getPlayerPoint() const {
    return point;
}

void Player::addPlayerPoint(int additionalPoint) {
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
    ability = NULL;
}

void Player::takeAbilityFromDeck(AbilityCard* _ability) {
    ability = _ability;
}

void Player::doAction(Game& game) {
    string input;
    bool invalidInput;
    do {
        invalidInput = false;
        cin >> input;
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
        else {
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

void Player::printCards() {
    cout << "Kartumu sekarang adalah:\n";
    cout << "1. ";
    cards[0].printCard();
    cout << "2. ";
    cards[1].printCard();
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
