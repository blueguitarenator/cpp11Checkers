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

	bool move(Checkers::Move move);
	void print(std::ostream& os);
	Checkers::Color getColor(int square) const;
	Memento* createMemento();
	std::vector<Checker*>& getComputerCheckers(){return m_black;}
private:
	std::vector<Square*> m_board;
	std::vector<Checker*> m_red;
	std::vector<Checker*> m_black;

	FRIEND_TEST(BoardTest, BoardSquares);
};

#endif /* BOARD_H_ */
