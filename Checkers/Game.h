/*
 * Game.h
 *
 *  Created on: Feb 25, 2013
 *      Author: richardjohnson
 */

#ifndef GAME_H_
#define GAME_H_

#include "Board.h"

class Game {
public:
	Game();
	virtual ~Game();

	void newGame();

private:
	Board m_board;
};

#endif /* GAME_H_ */
