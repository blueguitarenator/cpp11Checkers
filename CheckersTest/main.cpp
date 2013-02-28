/*
 * main.cpp
 *
 *  Created on: Feb 25, 2013
 *      Author: richardjohnson
 */
#include <memory>
#include <iostream>

#include <gtest/gtest.h>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

