/*
 * BoardTest.cpp
 *
 *  Created on: Feb 24, 2013
 *      Author: richardjohnson
 */
#include <Checkers/Board.h>
#include <gtest/gtest.h>
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


TEST(BoardTest, BoardSquares)
{
	Board b;

	int x = 0;
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	Square* sq = b.m_board.at(0);
	Square* nw = sq->m_nw;
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_nw);
	EXPECT_EQ(4, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_se);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_sw);
	x++;
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(4, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(5, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_se);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_sw);
	x++;
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(5, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(6, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_se);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_sw);
	x++; // 3
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(6, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(7, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_se);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_sw);
	x++; // 4
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(8, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(9, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(1, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(0, b.m_board.at(x)->m_sw->m_index);
	x++; // 5
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(9, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(10, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(2, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(1, b.m_board.at(x)->m_sw->m_index);
	x++; // 6
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(10, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(11, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(3, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(2, b.m_board.at(x)->m_sw->m_index);
	x++; // 7
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(11, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_ne);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_se);
	EXPECT_EQ(3, b.m_board.at(x)->m_sw->m_index);
	x++; // 8
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_nw);
	EXPECT_EQ(12, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(4, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_sw);
	x++; // 9
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(12, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(13, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(5, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(4, b.m_board.at(x)->m_sw->m_index);
	x++; // 10
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(13, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(14, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(6, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(5, b.m_board.at(x)->m_sw->m_index);
	x++; // 11
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(14, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(15, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(7, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(6, b.m_board.at(x)->m_sw->m_index);
	x++; // 12
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(16, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(17, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(9, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(8, b.m_board.at(x)->m_sw->m_index);
	x++; // 13
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(17, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(18, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(10, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(9, b.m_board.at(x)->m_sw->m_index);
	x++; // 14
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(18, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(19, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(11, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(10, b.m_board.at(x)->m_sw->m_index);
	x++; // 15
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(19, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_ne);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_se);
	EXPECT_EQ(11, b.m_board.at(x)->m_sw->m_index);
	x++; // 16
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_nw);
	EXPECT_EQ(20, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(12, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_sw);
	x++; // 17
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(20, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(21, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(13, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(12, b.m_board.at(x)->m_sw->m_index);
	x++; // 18
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(21, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(22, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(14, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(13, b.m_board.at(x)->m_sw->m_index);
	x++; // 19
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(22, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(23, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(15, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(14, b.m_board.at(x)->m_sw->m_index);
	x++; // 20
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(24, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(25, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(17, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(16, b.m_board.at(x)->m_sw->m_index);
	x++; // 21
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(25, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(26, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(18, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(17, b.m_board.at(x)->m_sw->m_index);
	x++; // 22
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(26, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(27, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(19, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(18, b.m_board.at(x)->m_sw->m_index);
	x++; // 23
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(27, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_ne);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_se);
	EXPECT_EQ(19, b.m_board.at(x)->m_sw->m_index);
	x++; // 24
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_nw);
	EXPECT_EQ(28, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(20, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_sw);
	x++; // 25
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(28, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(29, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(21, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(20, b.m_board.at(x)->m_sw->m_index);
	x++; // 26
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(29, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(30, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(22, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(21, b.m_board.at(x)->m_sw->m_index);
	x++; // 27
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(30, b.m_board.at(x)->m_nw->m_index);
	EXPECT_EQ(31, b.m_board.at(x)->m_ne->m_index);
	EXPECT_EQ(23, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(22, b.m_board.at(x)->m_sw->m_index);
	x++; // 28
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_nw);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_ne);
	EXPECT_EQ(25, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(24, b.m_board.at(x)->m_sw->m_index);
	x++; // 29
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_nw);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_ne);
	EXPECT_EQ(26, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(25, b.m_board.at(x)->m_sw->m_index);
	x++; // 30
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_nw);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_ne);
	EXPECT_EQ(27, b.m_board.at(x)->m_se->m_index);
	EXPECT_EQ(26, b.m_board.at(x)->m_sw->m_index);
	x++; // 31
	EXPECT_EQ(x, b.m_board.at(x)->m_index);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_nw);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_ne);
	EXPECT_EQ(nullptr, b.m_board.at(x)->m_se);
	EXPECT_EQ(27, b.m_board.at(x)->m_sw->m_index);
}
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


