/*
 * Square.cpp
 *
 *  Created on: Feb 24, 2013
 *      Author: richardjohnson
 */

#include "Square.h"
#include "Checker.h"

using namespace std;

Square::Square(int index)
: m_index(index),
  m_checker(nullptr),
  m_nw(nullptr),
  m_ne(nullptr),
  m_sw(nullptr),
  m_se(nullptr)
{

}

Square::~Square() {
}

bool Square::isEmpty()
{
	return m_checker == nullptr;
}

string Square::show()
{
	if (isEmpty())
	{
		 return "_";
	}
	return m_checker->show();
}
