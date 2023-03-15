#include "header/Deck.hpp"

Deck::Deck() : Inventory(52) {
    for (int i = 1; i <= 13; i++) {
        for (int j = 0; j <= 3; j++) {
            cards.push_back(MainCard(i, j));
        }
    }
    
    // initiate ability cards
    AbilityCard* card;
    
    card = new ReRoll;
    abilities.push_back(card);
    usedBy.emplace(card, -1);

    card = new Quadruple;
    abilities.push_back(card);
    usedBy.emplace(card, -1);
    
    card = new Quarter;
    abilities.push_back(card);
    usedBy.emplace(card, -1);
    
    card = new Reverse;
    abilities.push_back(card);
    usedBy.emplace(card, -1);
    
    card = new Swap;
    abilities.push_back(card);
    usedBy.emplace(card, -1);
    
    card = new Switch;
    abilities.push_back(card);
    usedBy.emplace(card, -1);

    card = new Abilityless;
    abilities.push_back(card);
    usedBy.emplace(card, -1);

    abilityCardTop = 6;  // 0..6, -1 means empty
}

Deck::~Deck() {
    for(AbilityCard* card : abilities) {
        delete card;
    }
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
    try {
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
                        throw InputInvalid();
                    }
                }
                else if (num == 1 && (*it - '0')<= 3) {
                    num *= 10;
                    num += *it - '0';
                }
                else throw InputInvalid();
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
                    else throw InputInvalid();
                }
                else {
                    throw InputInvalid();
                }
            }

            if (!(numRead && colorRead)) throw InputInvalid();

            MainCard inCard(num, color);
            if(cardTable[inCard]) throw DuplicateCardExist();
            
            cards[n] = MainCard(num, color);
            n++;
        }
    } catch (exception& err) {
        cout << err.what() << n+1 << '\n';
        throw InvalidFileSyntax();
    }
}

// Acak AbilityCard
void Deck::shuffleAbilityCards() {
    int size = abilities.size();
    
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        int idx = rand() % size;  // generate random index from 0..size
        // swap
        AbilityCard* temp = abilities[i];
        abilities[i] = abilities[idx];
        abilities[idx] = temp;
    }
}

// Cetak kartu
void Deck::printCards() {

}

AbilityCard* Deck::takeAbilityFromDeck(int n) {
    AbilityCard* ability = abilities[abilityCardTop];
    abilityCardTop--;
    usedBy[ability] = n;
    return ability;
}

void Deck::returnAbilityToDeck(AbilityCard * ability) {
    ability->setStatus(true);
    usedBy[ability] = -1;
    abilityCardTop++;
}
