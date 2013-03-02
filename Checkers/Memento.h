#pragma once

#include <map>

class Board;
class Checker;

class Memento
{
public:
	Memento(void);
	~Memento(void);

	std::map<int, Checker*> getSquareToCheckerMap(){return m_squareToCheckers;}
private:
	friend class Board;
	std::map<int, Checker*> m_squareToCheckers;
};


