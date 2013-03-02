/*
 * MoveMaker.h
 *
 *  Created on: Feb 28, 2013
 *      Author: richardjohnson
 */

#ifndef MOVEMAKER_H_
#define MOVEMAKER_H_

#include <vector>
#include "CheckerTypes.h"

class Board;
class Checker;
class Square;

class MoveMaker {
public:
	MoveMaker(const Board& board);
	virtual ~MoveMaker();

	Checkers::Move getMove();
private:
	std::vector<Square*> m_board;
	std::vector<Checker*> m_red;
	std::vector<Checker*> m_black;

};

#endif /* MOVEMAKER_H_ */
