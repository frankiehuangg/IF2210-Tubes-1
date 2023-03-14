#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <iostream>
#include "Comparable.hpp"
#include "Inventory.hpp"
#include "MainCard.hpp"
#include "Table.hpp"
#include "AbilityCard.hpp"
#include "Action.hpp"
#include "Deck.hpp"
#include "Exception.hpp"

#define C00 "\x1B[0m"
#define C01 "\x1B[31m"
#define C02 "\033[0;33m"
#define C03 "\x1B[32m"
#define C04 "\x1B[34m"
#define C05 "\x1b[38;5;238m"

using namespace std;

// Forward declaration
class Game;

class Player : public Inventory, public Comparable {
private:
	string name;
	int number;
	long long point;

	AbilityCard* ability;
	Action playerAction;

public:
	/***** Constructor dan destructor *****/
	/* Player constructor
	 * @param string name	Player name
	 * @param int number	Player number */
	Player(string, int);	

	/* Player destructor */
	~Player();

	/***** Getter & Setter *****/
	/* Returns the player's number */
	int getPlayerNumber() const;

	/* Returns the player's name */
	string getPlayerName() const;

	/* Returns the current player point */
	int getPlayerPoint() const;

	/* Add the current player point
	 * @param long long point		Added player point*/
	void addPlayerPoint(long long);

	/* Check whether player has AbilityCard */
	bool doesAbilityCardExist() const;

	/* Returns the status of player's AbilityCard */
	bool getAbilityCardStatus() const;

	/* Set the new AbilityCard status
	 * @param bool status		New card status */
	void setAbilityCardStatus(bool);

	/* Returns the AbilityCard back to Deck */
	void returnAbilityToDeck();

	/* Takes one abilityCard from deck
	 * @param Deck& deck	Deck */
	void takeAbilityFromDeck(Deck&);

	/* Starts player's action
	 * @param Game& game	Game */
	void doAction(Game&);

	/* Use AbilityCard's ability
	 * @param Game& game	Game */
	void useAbility(Game&);

	/***** Print *****/
	/* Prints the player's current card */
	void printCards();

	/* Checks whether the current player value > the other player value
	 * @param Comparable& other		The other player */
	bool operator< (Comparable&);

	/* Checks whether the current player value < the other player value
	 * @param Comparable& other		The other player */
	bool operator> (Comparable&);

	/* Checks whether the current player value == the other player value
	 * @param Comparable& other		The other player */
	bool operator== (Comparable&);

	/* Ostream operator used for cout
	 * @param ostream& os	ostream
	 * @param Player Player	player */
	friend ostream& operator<<(ostream&, Player);
};

#endif
