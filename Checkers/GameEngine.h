/*
 * GameEngine.h
 *
 *  Created on: Feb 27, 2013
 *      Author: richardjohnson
 */

#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_

class Board;

class GameEngine
{
public:
	GameEngine(Board& board);
	virtual ~GameEngine();

	void move();
private:
	Board& m_board;
};

#endif /* GAMEENGINE_H_ */
