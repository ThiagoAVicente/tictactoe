#include <iostream>
#include <vector>

#include "Node.h"

#ifndef BOARD_H
#define BOARD_H

#define SIZE 3

class Board {

private:


	Node::STATES static getNextPlayer(std::vector< std::vector < Node* > > board);

public:
	std::vector< std::vector < Node* > >* board = new std::vector< std::vector < Node* > >(SIZE, std::vector<Node*>(SIZE, nullptr));

	Board();

	bool static isEmpty(const std::vector< std::vector < Node* > >& board);

	std::vector< std::vector < Node* > > static play(std::pair<int, int> cord, std::vector< std::vector < Node* > > *board);

	std::vector< std::pair<int, int> > static getFrees(std::vector< std::vector < Node* > > board);

	void static printBoard(std::vector< std::vector < Node* > > &board);

	Node::STATES static calculateWinner(std::vector< std::vector < Node* > >& board);

	bool static isFull(std::vector< std::vector < Node* > >& board);
};

#endif