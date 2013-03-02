/*
 * Board.h
 *
 *  Created on: Feb 24, 2013
 *      Author: richardjohnson
 */

#ifndef BOARD_H_
#define BOARD_H_


#include <memory>
#include <vector>
#include "Square.h"
#include "CheckerTypes.h"
#include <fstream>
#include "Checker.h"
#include <gtest/gtest_prod.h>

class Memento;

class Board {
public:
	Board();
	virtual ~Board();
	Board(const Board&);

	bool move(Checkers::Move move, bool isJump);
	void print(std::ostream& os);
	std::vector<Checker*>& getComputerCheckers(){return m_black;}
	std::vector<Checker*>& getHumanCheckers(){return m_red;}

	Memento* createMemento();
	void reinstateMemento(Memento* memento);
	
private:
	std::vector<Square*> m_board;
	std::vector<Checker*> m_red;
	std::vector<Checker*> m_black;

	void removeChecker(Checker* checker);

	FRIEND_TEST(BoardTest, BoardSquares);
};

#endif /* BOARD_H_ */
