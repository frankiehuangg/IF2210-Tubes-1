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

using namespace std;

// Forward declaration
class Game;

class Player : public Inventory{
private:
	string name;
	int number;
	long long point;

	/* attribute to tell if player is still in the game*/
	bool status;

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
	long long getPlayerPoint() const;

	/* Returns the current player status */
	bool getPlayerStatus() const;

	/* Set the current player point 
	 * @param bool status		Changed status*/
	void setPlayerStatus(bool);

	/* Returns the current player Action */
	Action& getPlayerAction();

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

	/* Returns the status of ability card's disabled state */
	bool abilityDisabled() const;

	/* Disable the ability card owned by the player */
	void disableAbilityCard();

	/* Enable the ability card owned by the player */
	void enableAbilityCard();

	/* Returns the AbilityCard back to Deck */
	void returnAbilityToDeck(Deck&);

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

	/* Prints the player's info : ID (number), Name, Point, Ability (if available) */
	void printInfo();

	/* Prints the player's card specifier */
	void printCardsSpecifier();

	/* Checks whether the current player value > the other player value
	 * @param Player& other		The other player */
	bool operator< (Player&);

	/* Checks whether the current player value < the other player value
	 * @param Player& other		The other player */
	bool operator> (Player&);

	/* Checks whether the current player value == the other player value
	 * @param Player& other		The other player */
	bool operator== (Player&);

};

#endif
