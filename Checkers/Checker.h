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
	Checker(Square* square, Checkers::Color color);
	virtual ~Checker();

	int work(int x, int y);

	bool move(Checkers::DirectionType dir);
	std::string show();
	Checkers::Color getColor(){return m_color;}
	Checker* getNeighbor(Checkers::DirectionType dir);
	int getIndex();
private:
	Square* m_square;
	Checkers::Color m_color;
};

#endif /* CHECKER_H_ */
