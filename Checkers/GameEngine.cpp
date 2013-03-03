/*
 * GameEngine.cpp
 *
 *  Created on: Feb 27, 2013
 *      Author: richardjohnson
 */
#include "stdafx.h"
#include <vector>
#include <future>
#include <iostream>
#include "GameEngine.h"
#include "CheckerTypes.h"
#include "MoveMaker.h"

using namespace std;

GameEngine::GameEngine()
{

}

GameEngine::~GameEngine()
{
}

int foo()
{
	return 444;

}

void bar()
{
	cout << "YES" << endl;
}

// COMPUTER IS BLACK
void GameEngine::computerMove()
{
	Board boardCopy(m_board);
	MoveMaker mm(boardCopy);

	if (hasJump(Checkers::BLACK))
	{
		m_board.move(mm.getJump(), true);
	}
	else
	{

		m_board.move(mm.getMove(), false);
	}
	

//	future<int> f1 = async(foo);
	future<void> f1(async(bar));
}

bool GameEngine::humanMove(Checkers::Move move)
{
	return m_board.move(move, hasJump(Checkers::RED));
}

bool GameEngine::hasJump(Checkers::Color color)
{
	vector<Checker*> checkers;
	Checkers::DirectionType dir1;
	Checkers::DirectionType dir2;
	if (color == Checkers::BLACK)
	{
		checkers = m_board.getComputerCheckers();
		dir1 = Checkers::SW;
		dir2 = Checkers::SE;
	}
	else
	{
		checkers = m_board.getHumanCheckers();
		dir1 = Checkers::NW;
		dir2 = Checkers::NE;
	}
	for (auto it = checkers.begin(); it != checkers.end(); ++it)
	{
		Checker* checker = *it;
		if (checker->hasJump(dir1) || checker->hasJump(dir2))
		{
			return true;
		}
	}
	return false;
}

void GameEngine::showBoard()
{
	ofstream myfile;
	myfile.open ("game.txt", ios::out | ios::trunc);
	m_board.print(myfile);
	myfile.close();
}
