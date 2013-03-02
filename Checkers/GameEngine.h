/*
 * GameEngine.h
 *
 *  Created on: Feb 27, 2013
 *      Author: richardjohnson
 */

#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_

#include "CheckerTypes.h"
#include "Board.h"

class GameEngine
{
public:
	GameEngine();
	virtual ~GameEngine();

	bool hasJump(Checkers::Color color);
	void computerMove();
	bool humanMove(Checkers::Move move);
	void showBoard();
private:
	Board m_board;
};

#endif /* GAMEENGINE_H_ */
