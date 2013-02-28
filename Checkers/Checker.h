/*
 * Checker.h
 *
 *  Created on: Feb 24, 2013
 *      Author: richardjohnson
 */

#ifndef CHECKER_H_
#define CHECKER_H_

#include "Square.h"
#include "CheckerTypes.h"
#include <memory>
#include <string>

class Checker {
public:
	enum Color
	{
		RED,
		BLACK
	};
	Checker(Square* square, Color color);
	virtual ~Checker();

	int work(int x, int y);

	bool move(Checkers::DirectionType dir);
	std::string show();
	Color getColor(){return m_color;}
private:
	Square* m_square;
	Color m_color;
};

#endif /* CHECKER_H_ */
