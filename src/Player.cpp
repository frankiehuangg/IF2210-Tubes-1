#include "header/Player.hpp"

Player::Player(string _name, int _number) : Inventory(2)
{
    name = _name;
    number = _number;
    point = 0;
    status = true;

    ability = NULL;

    // Push dummmy elements for vector to allocate size beforehand
    /*
    MainCard dummy(-1, -1);
    cards.push_back(dummy);
    cards.push_back(dummy);
     */
    // initialize Action;
}

Player::~Player() {}

int Player::getPlayerNumber() const
{
    return number;
}

string Player::getPlayerName() const
{
    return name;
}

long long Player::getPlayerPoint() const
{
    return point;
}

bool Player::getPlayerStatus() const
{
    return status;
}

void Player::setPlayerStatus(bool status)
{
    this->status = status;
}

Action &Player::getPlayerAction()
{
    return playerAction;
}

void Player::addPlayerPoint(long long additionalPoint)
{
    point += additionalPoint;
}

bool Player::doesAbilityCardExist() const
{
    return ability != NULL;
}

bool Player::getAbilityCardStatus() const
{
    if (ability == NULL)
        throw NoAbilityAvailable();
    return ability->getStatus();
}

void Player::setAbilityCardStatus(bool status)
{
    ability->setStatus(status);
}

bool Player::abilityDisabled() const
{
    return ability->disabled();
}

void Player::disableAbilityCard()
{
    ability->disable();
}

void Player::enableAbilityCard()
{
    ability->enable();
}

void Player::returnAbilityToDeck(Deck &deck)
{
    deck.returnAbilityToDeck(ability);
    ability = NULL;
}

void Player::takeAbilityFromDeck(Deck &deck)
{
    ability = deck.takeAbilityFromDeck(number);
}

void Player::doAction(Game &game)
{
    string input;
    bool invalidInput = false;
    do
    {
        try {
            cout << "Masukkan input pengguna: ";
            cin >> input;
            if (input == "NEXT")
            {
                cout << "Giliran dilanjut ke pemain selanjutnya.\n";
            }
            else if (input == "RE-ROLL" || input == "QUADRUPLE" || input == "QUARTER" || input == "REVERSE" || input == "SWAPCARD" || input == "SWITCH" || input == "ABILITYLESS")
            {
                useAbility(game, input);
            }
            else if (input == "DOUBLE")
            {
                playerAction.actionDoDouble(game);
            }
            else if (input == "HALF")
            {
                playerAction.actionDoHalf(game);
            }
            else
            {
                throw NotExpected();
            }
        }
        catch (exception& err) {
            cout << err.what() << '\n';
        }
    } while (invalidInput);
}

void Player::useAbility(Game &game, string type)
{
    if (ability == NULL)
        throw NoAbilityAvailable();
    else
    {
        if(ability->getType() != type) throw NoAbilityAvailable(type);
        ability->useAbility(game);
    }
}

void Player::printCards()
{
    cout << (*this);
}

void Player::printInfo()
{
	cout << "\nPlayer Status" << endl;
    cout << "Number   \t: " << number << '\n';
    cout << "Name     \t: " << name << '\n';
    cout << "Point    \t: " << point << '\n';
    if (ability != NULL)
    {
        ability->printCard();
    }
}

void Player::printCardsSpecifier()
{
    vector<MainCard> cards = this->getInventoryCards();

    int size = cards.size();

    for (int i = 0; i < size; i++)
    {
        for (int i = 0; i < 6; i++)
            cout << " ";
        cout << i + 1;
        for (int i = 0; i < 7; i++)
            cout << " ";
    }
    cout << endl;
}

bool Player::operator<(Comparable &other)
{
    return point < other.getValue();
}

bool Player::operator>(Comparable &other)
{
    return point > other.getValue();
}

bool Player::operator==(Comparable &other)
{
    return point == other.getValue();
}
