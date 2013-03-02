/*
 * MoveMaker.cpp
 *
 *  Created on: Feb 28, 2013
 *      Author: richardjohnson
 */
#include "stdafx.h"
#include "MoveMaker.h"
#include "Board.h"
#include "Checker.h"
#include "Square.h"
#include "Memento.h"

using namespace std;

	/*
	 *   28  29  30  31
	 * 24  25  26  27
	 *   20  21  22  23
	 * 16  17  18  19
	 *   12  13  14  15
	 * 8   9   10  11
	 *   4   5   6   7
	 * 0   1   2   3
	 */

MoveMaker::MoveMaker(Board& board)
	:m_board(board)
{
	//for (int i = 0; i < 32; ++i)
	//{
	//	Checkers::Color color = board.getColor(i);
	//	Square* square = new Square(i);
	//	if (color == Checkers::RED)
	//	{
	//		Checker* checker = new Checker(square, color);
	//		m_red.push_back(checker);
	//	}
	//	else if (color == Checkers::BLACK)
	//	{
	//		Checker* checker = new Checker(square, color);
	//		m_black.push_back(checker);
	//	}

	//	m_board.push_back(square);
	//}
}

MoveMaker::~MoveMaker()
{
	//vector<Square*>::iterator it;
	//for (it = m_board.begin(); it != m_board.end(); ++it)
	//{
	//	delete *it;
	//	*it = nullptr;
	//}
	//vector<Checker*>::iterator it2;
	//for (it2 = m_red.begin(); it2 != m_red.end(); ++it2)
	//{
	//	delete *it2;
	//	*it2 = nullptr;
	//}
	//vector<Checker*>::iterator it3;
	//for (it3 = m_black.begin(); it3 != m_black.end(); ++it3)
	//{
	//	delete *it3;
	//	*it3 = nullptr;
	//}
}
// COMPUTER IS BLACK
Checkers::Move MoveMaker::getMove()
{
	Memento* memento = m_board.createMemento();

	Checkers::Move move = {Checkers::SW, 22};
	vector<Checker*> myCheckers = m_board.getComputerCheckers();
	vector<Checker*>::iterator it;
	for (it = myCheckers.begin(); it != myCheckers.end(); ++it)
	{
		Checker* checker = *it;
		Square* sq = (*it)->getSquare();
		if (checker->getNeighborSquare(Checkers::SW) != nullptr && checker->getNeighbor(Checkers::SW) == nullptr)
		{
			move.index = sq->getIndex();
			move.dir = Checkers::SW;
			break;
		}
		if (checker->getNeighborSquare(Checkers::SE) != nullptr && checker->getNeighbor(Checkers::SE) == nullptr)
		{
			move.index = sq->getIndex();
			move.dir = Checkers::SE;
			break;
		}
	}

	return move;
}

