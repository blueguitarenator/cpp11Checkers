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
 m_color(color)
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

Square* Checker::getNeighborSquare(Checkers::DirectionType dir)
{
	Square* square = nullptr;
	switch(dir)
	{
	case Checkers::NE:
		return m_square->getNE();
	case Checkers::NW:
		return m_square->getNW();
	case Checkers::SE:
		return m_square->getSE();
	case Checkers::SW:
		return m_square->getSW();
	default:
		break;
	}
	return square;
}

Checker* Checker::getNeighbor(Checkers::DirectionType dir)
{
	Checker* checker = nullptr;
	Square* square = nullptr;
	switch(dir)
	{
	case Checkers::NE:
		square = m_square->getNE();
		if (square != nullptr)
		{
			checker = square->getChecker();
		}
		break;
	case Checkers::NW:
		square = m_square->getNW();
		if (square != nullptr)
		{
			checker = square->getChecker();
		}
		break;
	case Checkers::SE:
		square = m_square->getSE();
		if (square != nullptr)
		{
			checker = square->getChecker();
		}
		break;
	case Checkers::SW:
		square = m_square->getSW();
		if (square != nullptr)
		{
			checker = square->getChecker();
		}
		break;
	default:
		break;
	}
	return checker;
}

string Checker::show()
{
	if (m_color == Checkers::RED)
	{
		return "X";
	}
	return "O";
}

int Checker::work(int x, int y)
{
	return x + y;
}

bool Checker::move(Checkers::DirectionType dir)
{
	if (dir == Checkers::NE)
	{
		if (m_square->getNE() != NULL && m_square->getNE()->isEmpty())
		{
			m_square->setChecker(nullptr);
			m_square->getNE()->setChecker(this);
			m_square = m_square->getNE();
			return true;
		}
	}
	else if (dir == Checkers::NW)
	{
		if (m_square->getNW() != NULL && m_square->getNW()->isEmpty())
		{
			m_square->setChecker(nullptr);
			m_square->getNW()->setChecker(this);
			m_square = m_square->getNW();
			return true;
		}
	}
	else if (dir == Checkers::SE)
	{
		if (m_square->getSE() != NULL && m_square->getSE()->isEmpty())
		{
			m_square->setChecker(nullptr);
			m_square->getSE()->setChecker(this);
			m_square = m_square->getSE();
			return true;
		}
	}
	else
	{
		if (m_square->getSW() != NULL && m_square->getSW()->isEmpty())
		{
			m_square->setChecker(nullptr);
			m_square->getSW()->setChecker(this);
			m_square = m_square->getSW();
			return true;
		}
	}
	return false;
}
