/*
 * CheckerTest.cpp
 *
 *  Created on: Feb 24, 2013
 *      Author: richardjohnson
 */

#include <Checkers/Checker.h>
#include <Checkers/Square.h>
#include <Checkers/CheckerTypes.h>
#include <memory>
#include <gtest/gtest.h>

using namespace std;

TEST(CheckerTest, asdf)
{
	Square sq(0);
	Checker c(&sq, Checkers::RED);
	EXPECT_EQ(20, c.work(2, 18));
	//int x = 0;
}



