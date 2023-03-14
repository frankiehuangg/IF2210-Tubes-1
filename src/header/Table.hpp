#ifndef _TABLE_HPP_
#define _TABLE_HPP_

#include "Inventory.hpp"
#include "MainCard.hpp"

using namespace std;

class Table : public Inventory {
private:
	int opened;

public:

	/***** Constructor *****/
	/* Table constructor */
	Table();

	/***** Getter & Setter *****/
	/* Returns the amount of cards opened */
	int getOpened() const;

	/* Set the amount of cards opened
	 * @param int opened	New opened value */
	void setOpened(int);

	/* Adds the amount of cards opened by 1 */
	void openCard();

	/* Prints the table cards */
	void printCards();

	/* Ostream operator used for cout
	 * @param ostream& os	ostream
	 * @param Player player Player */
	friend ostream& operator<< (ostream&, Table);
};

#endif
