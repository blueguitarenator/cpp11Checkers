/*
 * Checker.cpp
 *
 *  Created on: Feb 24, 2013
 *      Author: richardjohnson
 */
#include "stdafx.h"
#include "Checker.h"
#include <memory>

using namespace std;

Checker::Checker(Square* square, Checkers::Color color)
:m_square(square),
 m_myColor(color)
{
	m_square->setChecker(this);
}

Checker::~Checker()
{

}

int Checker::getIndex()
{
	return m_square->getIndex();
}

string Checker::show()
{
	if (m_myColor == Checkers::RED)
	{
		return "X";
	}
	return "O";
}

int Checker::work(int x, int y)
{
	return x + y;
}

bool Checker::hasJump(Checkers::DirectionType dir)
{
	Square* neighbor = Checkers::getNeighborSquare(m_square, dir);
	if (neighbor != nullptr)
	{
		Checker* checker = neighbor->getChecker();
		if (checker != nullptr && checker->getColor() != m_myColor)
		{
			Square* jumpSquare = Checkers::getNeighborSquare(neighbor, dir);
			if (jumpSquare != nullptr && jumpSquare->getChecker() == nullptr)
			{
				return true;
			}
		}
	}
	return false;
}
