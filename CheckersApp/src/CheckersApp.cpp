

//============================================================================
// Name        : CheckersApp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "stdafx.h"
#include <iostream>
#include <Checkers/CheckerTypes.h>
#include <Checkers/GameEngine.h>
#include <fstream>

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

int main()
{
	GameEngine engine;
	engine.showBoard();
	Checkers::Move move = {Checkers::NE, 0};
	while (move.index != 666)
	{
		cout << "Your Move" << endl;
		bool moved = false;
		while (!moved)
		{
			cin >> move.index;
			if (move.index > 31) continue;
			cout << "Direction" << endl;
			int dir;
			cin >> dir;
			move.dir = static_cast<Checkers::DirectionType>(dir);
			moved = engine.humanMove(move);
			if (!moved)
			{
				cout << "Invalid move or you must jump" << endl;
			}
		}

		engine.showBoard();
		engine.computerMove();
		cout << "Computer moved" << endl;
		engine.showBoard();
	}

	cout << "!!!Goodbye Checkers!!!" << endl;
	return 0;
}
