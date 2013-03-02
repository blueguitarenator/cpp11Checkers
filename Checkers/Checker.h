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

	//bool move(Checkers::DirectionType dir);
	//bool jump(Checkers::DirectionType dir);
	std::string show();
	Checkers::Color getColor(){return m_myColor;}
	int getIndex();
	Square* getSquare(){return m_square;}
	bool hasJump(Checkers::DirectionType dir);
	void setSquare(Square* sq){m_square = sq;}
private:
	Square* m_square;
	Checkers::Color m_myColor;
};

#endif /* CHECKER_H_ */
