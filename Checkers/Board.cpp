/*
 * Board.cpp
 *
 *  Created on: Feb 24, 2013
 *      Author: richardjohnson
 */
#include "stdafx.h"
#include "Board.h"

using namespace std;

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

void linkBoard(vector<Square*>& board);

Board::Board()
{
	for (int i = 0; i < 32; ++i)
	{
		m_board.push_back(new Square(i));
	}
	m_red.push_back(new Checker(m_board.at(0), Checkers::RED));
	m_red.push_back(new Checker(m_board.at(1), Checkers::RED));
	m_red.push_back(new Checker(m_board.at(2), Checkers::RED));
	m_red.push_back(new Checker(m_board.at(3), Checkers::RED));
	m_red.push_back(new Checker(m_board.at(4), Checkers::RED));
	m_red.push_back(new Checker(m_board.at(5), Checkers::RED));
	m_red.push_back(new Checker(m_board.at(6), Checkers::RED));
	m_red.push_back(new Checker(m_board.at(7), Checkers::RED));
	m_red.push_back(new Checker(m_board.at(8), Checkers::RED));
	m_red.push_back(new Checker(m_board.at(9), Checkers::RED));
	m_red.push_back(new Checker(m_board.at(10), Checkers::RED));
	m_red.push_back(new Checker(m_board.at(11), Checkers::RED));
	m_black.push_back(new Checker(m_board.at(20), Checkers::BLACK));
	m_black.push_back(new Checker(m_board.at(21), Checkers::BLACK));
	m_black.push_back(new Checker(m_board.at(22), Checkers::BLACK));
	m_black.push_back(new Checker(m_board.at(23), Checkers::BLACK));
	m_black.push_back(new Checker(m_board.at(24), Checkers::BLACK));
	m_black.push_back(new Checker(m_board.at(25), Checkers::BLACK));
	m_black.push_back(new Checker(m_board.at(26), Checkers::BLACK));
	m_black.push_back(new Checker(m_board.at(27), Checkers::BLACK));
	m_black.push_back(new Checker(m_board.at(28), Checkers::BLACK));
	m_black.push_back(new Checker(m_board.at(29), Checkers::BLACK));
	m_black.push_back(new Checker(m_board.at(30), Checkers::BLACK));
	m_black.push_back(new Checker(m_board.at(31), Checkers::BLACK));

	linkBoard(m_board);

}

Board::Board(const Board& cpy)
{
	for (auto it = cpy.m_board.begin(); it != cpy.m_board.end(); ++it)
	{
		Square* otherSquare = *it;
		Square* sq = new Square(otherSquare->getIndex());
		Checker* otherChecker = otherSquare->getChecker();
		if (otherChecker != nullptr)
		{
			Checkers::Color color = otherChecker->getColor();
			Checker* checker = new Checker(sq, color);
			if (color == Checkers::BLACK)
			{
				m_black.push_back(checker);
			}
			else
			{
				m_red.push_back(checker);
			}
		}
		m_board.push_back(sq);
	}
	linkBoard(m_board);
}

Board::~Board()
{
	for (auto it = m_board.begin(); it != m_board.end(); ++it)
	{
		Checker* checker = (*it)->getChecker();
		if (checker != nullptr)
		{
			delete checker;
			checker = nullptr;
		}
		delete *it;
	}
}

Memento* Board::createMemento()
{
	return nullptr;
}

void Board::reinstateMemento(Memento* memento)
{

}

void linkBoard(vector<Square*>& board)
{
	int x = 0;
	board.at(x)->setSW(nullptr);board.at(x)->setSE(nullptr);           board.at(x)->setNW(nullptr);           board.at(x)->setNE(board.at(x+4));
	x = 1;
	board.at(x)->setSW(nullptr);           board.at(x)->setSE(nullptr);           board.at(x)->setNW(board.at(x+3));board.at(x)->setNE(board.at(x+4));
	x = 2;
	board.at(x)->setSW(nullptr);           board.at(x)->setSE(nullptr);           board.at(x)->setNW(board.at(x+3));board.at(x)->setNE(board.at(x+4));
	x = 3;
	board.at(x)->setSW(nullptr);           board.at(x)->setSE(nullptr);           board.at(x)->setNW(board.at(x+3));board.at(x)->setNE(board.at(x+4));
	x = 4;
	board.at(x)->setSW(board.at(x-4));board.at(x)->setSE(board.at(x-3));board.at(x)->setNW(board.at(x+4));board.at(x)->setNE(board.at(x+5));
	x = 5;
	board.at(x)->setSW(board.at(x-4));board.at(x)->setSE(board.at(x-3));board.at(x)->setNW(board.at(x+4));board.at(x)->setNE(board.at(x+5));
	x = 6;
	board.at(x)->setSW(board.at(x-4));board.at(x)->setSE(board.at(x-3));board.at(x)->setNW(board.at(x+4));board.at(x)->setNE(board.at(x+5));
	x = 7;
	board.at(x)->setSW(board.at(x-4));board.at(x)->setSE(nullptr);           board.at(x)->setNW(board.at(x+4));board.at(x)->setNE(nullptr);
	x = 8;
	board.at(x)->setSW(nullptr);           board.at(x)->setSE(board.at(x-4));board.at(x)->setNW(nullptr);           board.at(x)->setNE(board.at(x+4));
	x = 9;
	board.at(x)->setSW(board.at(x-5));board.at(x)->setSE(board.at(x-4));board.at(x)->setNW(board.at(x+3));board.at(x)->setNE(board.at(x+4));
	x = 10;
	board.at(x)->setSW(board.at(x-5));board.at(x)->setSE(board.at(x-4));board.at(x)->setNW(board.at(x+3));board.at(x)->setNE(board.at(x+4));
	x = 11;
	board.at(x)->setSW(board.at(x-5));board.at(x)->setSE(board.at(x-4));board.at(x)->setNW(board.at(x+3));board.at(x)->setNE(board.at(x+4));
	x = 12;
	board.at(x)->setSW(board.at(x-4));board.at(x)->setSE(board.at(x-3));board.at(x)->setNW(board.at(x+4));board.at(x)->setNE(board.at(x+5));
	x = 13;
	board.at(x)->setSW(board.at(x-4));board.at(x)->setSE(board.at(x-3));board.at(x)->setNW(board.at(x+4));board.at(x)->setNE(board.at(x+5));
	x = 14;
	board.at(x)->setSW(board.at(x-4));board.at(x)->setSE(board.at(x-3));board.at(x)->setNW(board.at(x+4));board.at(x)->setNE(board.at(x+5));
	x = 15;
	board.at(x)->setSW(board.at(x-4));board.at(x)->setSE(nullptr);           board.at(x)->setNW(board.at(x+4));board.at(x)->setNE(nullptr);
	x = 16;
	board.at(x)->setSW(nullptr);           board.at(x)->setSE(board.at(x-4));board.at(x)->setNW(nullptr);           board.at(x)->setNE(board.at(x+4));
	x = 17;
	board.at(x)->setSW(board.at(x-5));board.at(x)->setSE(board.at(x-4));board.at(x)->setNW(board.at(x+3));board.at(x)->setNE(board.at(x+4));
	x = 18;
	board.at(x)->setSW(board.at(x-5));board.at(x)->setSE(board.at(x-4));board.at(x)->setNW(board.at(x+3));board.at(x)->setNE(board.at(x+4));
	x = 19;
	board.at(x)->setSW(board.at(x-5));board.at(x)->setSE(board.at(x-4));board.at(x)->setNW(board.at(x+3));board.at(x)->setNE(board.at(x+4));
	x = 20;
	board.at(x)->setSW(board.at(x-4));board.at(x)->setSE(board.at(x-3));board.at(x)->setNW(board.at(x+4));board.at(x)->setNE(board.at(x+5));
	x = 21;
	board.at(x)->setSW(board.at(x-4));board.at(x)->setSE(board.at(x-3));board.at(x)->setNW(board.at(x+4));board.at(x)->setNE(board.at(x+5));
	x = 22;
	board.at(x)->setSW(board.at(x-4));board.at(x)->setSE(board.at(x-3));board.at(x)->setNW(board.at(x+4));board.at(x)->setNE(board.at(x+5));
	x = 23;
	board.at(x)->setSW(board.at(x-4));board.at(x)->setSE(nullptr);           board.at(x)->setNW(board.at(x+4));board.at(x)->setNE(nullptr);
	x = 24;
	board.at(x)->setSW(nullptr);           board.at(x)->setSE(board.at(x-4));board.at(x)->setNW(nullptr);           board.at(x)->setNE(board.at(x+4));
	x = 25;
	board.at(x)->setSW(board.at(x-5));board.at(x)->setSE(board.at(x-4));board.at(x)->setNW(board.at(x+3));board.at(x)->setNE(board.at(x+4));
	x = 26;
	board.at(x)->setSW(board.at(x-5));board.at(x)->setSE(board.at(x-4));board.at(x)->setNW(board.at(x+3));board.at(x)->setNE(board.at(x+4));
	x = 27;
	board.at(x)->setSW(board.at(x-5));board.at(x)->setSE(board.at(x-4));board.at(x)->setNW(board.at(x+3));board.at(x)->setNE(board.at(x+4));
	x = 28;
	board.at(x)->setSW(board.at(x-4));board.at(x)->setSE(board.at(x-3));board.at(x)->setNW(nullptr);           board.at(x)->setNE(nullptr);
	x = 29;
	board.at(x)->setSW(board.at(x-4));board.at(x)->setSE(board.at(x-3));board.at(x)->setNW(nullptr);           board.at(x)->setNE(nullptr);
	x = 30;
	board.at(x)->setSW(board.at(x-4));board.at(x)->setSE(board.at(x-3));board.at(x)->setNW(nullptr);           board.at(x)->setNE(nullptr);
	x = 31;
	board.at(x)->setSW(board.at(x-4));board.at(x)->setSE(nullptr);           board.at(x)->setNW(nullptr);           board.at(x)->setNE(nullptr);
}

void Board::print(ostream& os)
{
	os << "The board\n";
	os << "  | " << m_board.at(28)->show() << " | " << m_board.at(29)->show() << " | " << m_board.at(30)->show() << " | " << m_board.at(31)->show() << " | \n";
	os << "| " << m_board.at(24)->show() << " | " << m_board.at(25)->show() << " | " << m_board.at(26)->show() << " | " << m_board.at(27)->show() << " | \n";
	os << "  | " << m_board.at(20)->show() << " | " << m_board.at(21)->show() << " | " << m_board.at(22)->show() << " | " << m_board.at(23)->show() << " | \n";
	os << "| " << m_board.at(16)->show() << " | " << m_board.at(17)->show() << " | " << m_board.at(18)->show() << " | " << m_board.at(19)->show() << " | \n";
	os << "  | " << m_board.at(12)->show() << " | " << m_board.at(13)->show() << " | " << m_board.at(14)->show() << " | " << m_board.at(15)->show() << " | \n";
	os << "| " << m_board.at(8)->show() << " | " << m_board.at(9)->show() << " | " << m_board.at(10)->show() << " | " << m_board.at(11)->show() << " | \n";
	os << "  | " << m_board.at(4)->show() << " | " << m_board.at(5)->show() << " | " << m_board.at(6)->show() << " | " << m_board.at(7)->show() << " | \n";
	os << "| " << m_board.at(0)->show() << " | " << m_board.at(1)->show() << " | " << m_board.at(2)->show() << " | " << m_board.at(3)->show() << " | \n";
	os << "\n";
	os << "  | " << "28" << " | " << "29" << " | " << "30" << " | " << "31" << " |\n";
	os << "| " << "24" << " | " << "25" << " | " << "26" << " | " << "27" << " |\n";
	os << "  | " << "20" << " | " << "21" << " | " << "22" << " | " << "23" << " |\n";
	os << "| " << "16" << " | " << "17" << " | " << "18" << " | " << "19" << " |\n";
	os << "  | " << "12" << " | " << "13" << " | " << "14" << " | " << "15" << " |\n";
	os << "| " << "08" << " | " << "09" << " | " << "10" << " | " << "11" << " |\n";
	os << "  | " << "04" << " | " << "05" << " | " << "06" << " | " << "07" << " |\n";
	os << "| " << "00" << " | " << "01" << " | " << "02" << " | " << "03" << " |\n";
	os << "NW(0) NE(1) SW(2) SE(3)\n";
}

bool Board::move(Checkers::Move move, bool isJump)
{
	if (move.index >= 0)
	{
		auto square = m_board.at(move.index);
		if (!square->isEmpty())
		{
			auto checker = square->getChecker();
			if (isJump)
			{
				Square* neighbor = Checkers::getNeighborSquare(square, move.dir);
				Square* jumpSquare = Checkers::getNeighborSquare(neighbor, move.dir);
				Checker* jumpedChecker = neighbor->getChecker();
				neighbor->setChecker(nullptr);
				square->setChecker(nullptr);
				jumpSquare->setChecker(checker);
				checker->setSquare(jumpSquare);
				removeChecker(jumpedChecker);
				return true;
			}
			else
			{
				Square* neighbor = Checkers::getNeighborSquare(square, move.dir);
				if (neighbor != nullptr && neighbor->isEmpty())
				{
					square->setChecker(nullptr);
					neighbor->setChecker(checker);
					checker->setSquare(neighbor);
					return true;
				}
			}
		}
	}
	return false;
}

void Board::removeChecker(Checker* checker)
{
	auto it = m_red.begin();
	for (; it != m_red.end(); ++it)
	{
		if (*it == checker)
		{
			break;
		}
	}
	if (it != m_red.end())
	{
		m_red.erase(it);
		delete checker;
		checker = nullptr;
	}
	else
	{
		it = m_black.begin();
		for (; it != m_black.end(); ++it)
		{
			if (*it == checker)
			{
				break;
			}
		}
		if (it != m_black.end())
		{
			m_black.erase(it);
			delete checker;
			checker = nullptr;
		}
	}
}
