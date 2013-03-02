/*
 * MoveMaker.cpp
 *
 *  Created on: Feb 28, 2013
 *      Author: richardjohnson
 */

#include "MoveMaker.h"
#include "Board.h"
#include "Checker.h"
#include "Square.h"

using namespace std;

MoveMaker::MoveMaker(const Board& board)
{
	for (int i = 0; i < 32; ++i)
	{
		Checkers::Color color = board.getColor(i);
		Square* square = new Square(i);
		if (color == Checkers::RED)
		{
			Checker* checker = new Checker(square, color);
			m_red.push_back(checker);
		}
		else if (color == Checkers::BLACK)
		{
			Checker* checker = new Checker(square, color);
			m_black.push_back(checker);
		}

		m_board.push_back(square);
	}
}

MoveMaker::~MoveMaker()
{
	vector<Square*>::iterator it;
	for (it = m_board.begin(); it != m_board.end(); ++it)
	{
		delete *it;
		*it = nullptr;
	}
	vector<Checker*>::iterator it2;
	for (it2 = m_red.begin(); it2 != m_red.end(); ++it2)
	{
		delete *it2;
		*it2 = nullptr;
	}
	vector<Checker*>::iterator it3;
	for (it3 = m_black.begin(); it3 != m_black.end(); ++it3)
	{
		delete *it3;
		*it3 = nullptr;
	}
}

Checkers::Move MoveMaker::getMove()
{
	Checkers::Move move;
	vector<Checker*>::iterator it;
	for (it = m_black.begin(); it != m_black.end(); ++it)
	{
		Checker* checker = (*it)->getNeighbor(Checkers::SW);
		if (checker != nullptr && checker->getColor() == Checkers::EMPTY)
		{
			move.index = checker->getIndex();
			move.dir = Checkers::SW;
			break;
		}
		checker = (*it)->getNeighbor(Checkers::SE);
		if (checker != nullptr && checker->getColor() == Checkers::EMPTY)
		{
			move.index = checker->getIndex();
			move.dir = Checkers::SE;
			break;
		}
	}

	return move;
}

