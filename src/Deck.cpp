#include "header/Deck.hpp"

Deck::Deck() : Inventory(52) {
    for (int i = 1; i <= 13; i++) {
        for (int j = 0; j <= 3; j++) {
            cards.push_back(MainCard(i, j));
        }
    }

    // initiate ability cards
    abilities.push_back(ReRoll());
    abilities.push_back(Quadruple());
    abilities.push_back(Quarter());
    abilities.push_back(Reverse());
    abilities.push_back(Swap());
    abilities.push_back(Switch());
    abilities.push_back(Abilityless());

    for(int i = 0; i < 7; i++) {
        AbilityCard* card = &abilities[i];
        usedBy.emplace(card, -1);
    }

    abilityCardTop = 6;  // 0..6, -1 means empty
}

// Acak MainCard
void Deck::shuffleMainCards() {
    int size = cards.size();
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        int idx = rand() % size;  // generate random index from 0..size
        // swap
        MainCard temp = cards[i];
        cards[i] = cards[idx];
        cards[idx] = temp;
    }
}

// Baca urutan deck dari file
void Deck::getDeckFromInput() {
    cout << "Input nama file: ";
    string filename;
    getline(cin, filename);
    getchar(); // consume \n delimiter from getline

    ifstream fin(filename);
    if(!fin.is_open()) throw InvalidFileSyntax();

    // create card table to check for duplicate card during input
    map<MainCard, bool> cardTable;
    for (int i = 1; i <= 13; i++) {
        for (int j = 0; j <= 3; j++) {
            cardTable.emplace(MainCard(i, j), false);
        }
    }

    // parse input
    string line;
    int n = 0;
    while(getline(fin, line)) {
        bool numRead = false, colorRead = true;
        int num, color;
        num = 1;
        color = 0;

        string::iterator it;
        // read card number
        for(it = line.begin(); it != line.end(); ++it) {
            if(!numRead) {
                if (*it == ' ') {
                    continue;
                }
                else if (isdigit(*it)) {
                    int temp = *it - '0';
                    if(temp == 0) {
                        continue;
                    }
                    num = temp;
                    numRead = true;
                }
                else {
                    throw InputInvalid(n+1);
                }
            }
            else if (num == 1 && (*it - '0')<= 3) {
                num *= 10;
                num += *it - '0';
            }
            else throw InputInvalid(n+1);
        }

        // read card color
        for(/* it = it */; it != line.end(); ++it) {
            if (*it == ' ') {
                continue;
            }
            else if (isdigit(*it) && !colorRead) {
                int temp = *it - '0';
                if(temp == 0) {
                    continue;
                }
                else if (0 <= temp && temp <= 3){
                    color = temp;
                    colorRead = true;
                }
                else throw InputInvalid(n+1);
            }
            else {
                throw InputInvalid(n+1);
            }
        }

        if (!(numRead && colorRead)) throw InputInvalid(n+1);

        MainCard inCard(num, color);
        if(cardTable[inCard]) throw DuplicateCardExist(n+1);
        
        cards[n] = MainCard(num, color);
        n++;
    }
}

// Acak AbilityCard
void Deck::shuffleAbilityCards() {
    deque<AbilityCard> shuffledDeck;

    int size = abilities.size();
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        int idx = rand() % 2;  // generate random index to push from front or back
        if(idx == 1){
            shuffledDeck.push_back(abilities[i]);
        }
        else {
            shuffledDeck.push_front(abilities[i]);
        }
    }
    abilities.clear();
    while(!shuffledDeck.empty()) {
        abilities.push_back(shuffledDeck.front());
        shuffledDeck.pop_front();
    }
}

// Cetak kartu
void Deck::printCards() {

}

AbilityCard* Deck::takeAbilityFromDeck(int n) {
    AbilityCard* ability = &abilities[abilityCardTop];
    abilityCardTop--;
    usedBy[ability] = n;
    return ability;
}

void Deck::returnAbilityToDeck(AbilityCard * ability) {
    ability->setStatus(true);
    usedBy[ability] = -1;
    abilityCardTop++;
}
