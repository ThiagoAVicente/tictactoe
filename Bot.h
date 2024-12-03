#include <iostream>
#include <vector>
#include <random>

#include "Node.h"
#include "Board.h"


#ifndef BOT_H
#define BOT_H


class Bot {

private: 
	bool static justOne(std::vector< std::vector < Node* > > board);

public:
	//fUNCTIONS DECLARATION
	void static organizePlay(Board board);
	std::vector< std::vector < Node* > >static *copyBoard(std::vector< std::vector < Node* > >& board);
	int static minValue(std::vector< std::vector < Node* > > * testing, bool srt);
	int static maxValue(std::vector< std::vector < Node* > >* testing, bool srt);
	int static getMax(int a, int b);
	int static getMin(int a, int b);
};
#endif