//============================================================================
// Name        : CheckersApp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <Checkers/Board.h>
#include <Checkers/CheckerTypes.h>
#include <Checkers/GameEngine.h>
#include <fstream>

using namespace std;

void print(Board& b);
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
	Board b;
	GameEngine engine(b);

	print(b);
	int piece = 0;
	int dir = -1;
	while (piece != 666)
	{
		Checkers::Move move;
		cout << "Your Move" << endl;
		cin >> move.index;
		cout << "Direction" << endl;
		cin >> dir;
		if (dir == 0)
		{
			move.dir = Checkers::NW;
			b.move(move);
		}
		else if (dir == 1)
		{
			move.dir = Checkers::NE;
			b.move(move);
		}
		else if (dir == 2)
		{
			move.dir = Checkers::SW;
			b.move(move);
		}
		else if (dir == 3)
		{
			move.dir = Checkers::SE;
			b.move(move);
		}
		print(b);
		engine.move();
		cout << "Computer moved" << endl;
		print(b);
	}

	cout << "!!!Goodbye Checkers!!!" << endl;
	return 0;
}

void print(Board& b)
{
	ofstream myfile;
	myfile.open ("game.txt", ios::out | ios::trunc);
	b.print(myfile);

	myfile.close();

}
