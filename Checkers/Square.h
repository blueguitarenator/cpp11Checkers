/*
 * Square.h
 *
 *  Created on: Feb 24, 2013
 *      Author: richardjohnson
 */

#ifndef SQUARE_H_
#define SQUARE_H_
#include <string>
#include <memory>
#include <gtest/gtest_prod.h>

class Checker;

class Square {
public:
	Square(int index);
	virtual ~Square();

	bool isEmpty();
	void setNW(Square* sq){m_nw = sq;}
	void setNE(Square* sq){m_ne = sq;}
	void setSW(Square* sq){m_sw = sq;}
	void setSE(Square* sq){m_se = sq;}
	Square* getNW(){return m_nw;}
	Square* getNE(){return m_ne;}
	Square* getSW(){return m_sw;}
	Square* getSE(){return m_se;}
	void setChecker(Checker* checker){m_checker = checker;}
	Checker* getChecker(){return m_checker;}
	std::string show();
	int getIndex(){return m_index;}
private:
	int m_index;
	Checker* m_checker;

	Square* m_nw;
	Square* m_ne;
	Square* m_sw;
	Square* m_se;

	FRIEND_TEST(BoardTest, BoardSquares);

};

#endif /* SQUARE_H_ */
