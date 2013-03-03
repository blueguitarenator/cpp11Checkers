/*
 * CheckerTypes.h
 *
 *  Created on: Feb 26, 2013
 *      Author: richardjohnson
 */

#ifndef CHECKERTYPES_H_
#define CHECKERTYPES_H_

#include "Square.h"

/*
Evaluation notes
(# of my checkers on board) - (# of opponent's checkers on board). 
"# of exposed checkers", "# of protected checkers", 
"# of squares controlled in middle of board"

The linear handcrafted evaluation function considers several features of the game board, 
including piece count, kings count, trapped kings, turn, 
runaway checkers (unimpeded path to be kinged) and other minor factors.


+K   Player's King
+1   Player's Man
 0      Empty
-1   Opponent's Man
-K   Opponent's King

  K is an evolvable value, initialized to 2.0.

*/
namespace Checkers
{

	enum Color
	{
		RED,
		BLACK
	};

	enum DirectionType
	{
		NW,
		NE,
		SW,
		SE
	};

	struct Move
	{
		DirectionType dir;
		int index;
	};

	struct EvaluatedMove
	{
		Move move;
		double score;
	};

	enum Color
	{
		RED,
		BLACK
	};
	
	static Square* getNeighborSquare(Square* sq, Checkers::DirectionType dir)
	{
		switch(dir)
		{
		case Checkers::NW:
			return sq->getNW();
		case Checkers::NE:
			return sq->getNE();
		case Checkers::SW:
			return sq->getSW();
		case Checkers::SE:
			return sq->getSE();
		default:
			return nullptr;
		}
	}
}

#endif /* CHECKERTYPES_H_ */
