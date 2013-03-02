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

MoveMaker::MoveMaker(Board& board)
	:m_board(board)
{
}

MoveMaker::~MoveMaker()
{
}

// COMPUTER IS BLACK

// just gets the first jump it finds for now
Checkers::Move MoveMaker::getJump()
{
	Checkers::Move move = {Checkers::SW, 22};
	vector<Checker*> myCheckers = m_board.getComputerCheckers();
	vector<Checker*>::iterator it;
	for (it = myCheckers.begin(); it != myCheckers.end(); ++it)
	{
		Checker* checker = *it;
		Square* sq = (*it)->getSquare();

		Square* neighbor = sq->getSW();
		if (neighbor != nullptr && neighbor->getChecker() != nullptr)
		{
			Checker* neighborChecker = neighbor->getChecker();
			if (neighborChecker->getColor() == Checkers::RED)
			{
				Square* jumpSquare = neighbor->getSW();
				if (jumpSquare != nullptr && jumpSquare->getChecker() == nullptr)
				{
					move.index = checker->getIndex();
					move.dir = Checkers::SW;
					break;
				}
			}
		}
		neighbor =sq->getSE();
		if (neighbor != nullptr && neighbor->getChecker() != nullptr)
		{
			Checker* neighborChecker = neighbor->getChecker();
			if (neighborChecker->getColor() == Checkers::RED)
			{
				Square* jumpSquare = neighbor->getSE();
				if (jumpSquare != nullptr && jumpSquare->getChecker() == nullptr)
				{
					move.index = checker->getIndex();
					move.dir = Checkers::SE;
					break;
				}
			}
		}
	}
	return move;
}

// just gets the first move it finds for now
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
		Square* neighbor = sq->getSW();
		if (neighbor != nullptr && neighbor->getChecker() == nullptr)
		{
			move.index = sq->getIndex();
			move.dir = Checkers::SW;
			break;
		}
		neighbor = sq->getSE();
		if (neighbor != nullptr && neighbor->getChecker() == nullptr)
		{
			move.index = sq->getIndex();
			move.dir = Checkers::SE;
			break;
		}
	}

	return move;
}

