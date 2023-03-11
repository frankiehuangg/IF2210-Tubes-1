#include "header\Player.hpp"

Player::Player(string _name) : Inventory(2) {
    name = _name;
    point = 0;

    ability = NULL;
    value = 0;

    // Push dummmy elements for vector to allocate size beforehand
    MainCard dummy(-1, -1);
    cards.push_back(dummy);
    cards.push_back(dummy);
}

Player::~Player() {
    delete ability;
}

const pair<MainCard, MainCard> Player::getCards() {
    return make_pair(cards[0], cards[1]);
}

void Player::setCards(pair<MainCard, MainCard> newCards) {
    cards[0] = newCards.first;
    cards[1] = newCards.second;
}

void Player::useAbility() {
    if (ability == NULL) throw NoAbilityAvailable();
    else {
        ability->useAbility();
    }
}

void Player::printCards() {
    cout << "Kartumu sekarang adalah:\n";
    cout << "1. ";
    cards[0].printCard();
    // cout << " && ";
    cout << "2. ";
    cards[1].printCard();
    // cout << '\n';
}

// Cek apakah nilai kombo player > player lain
bool Player::operator< (Comparable& other) {
    
}

// Cek apakah nilai kombo player < player lain
bool Player::operator> (Comparable& other) {

}

// Cek apakah nilai kombo player = player lain
bool Player::operator== (Comparable& other) {
    
}