/*
 * CheckerTypes.h
 *
 *  Created on: Feb 26, 2013
 *      Author: richardjohnson
 */

#ifndef CHECKERTYPES_H_
#define CHECKERTYPES_H_

#include "Square.h"

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
