#include "Board.h"

	Node::STATES Board::getNextPlayer(std::vector< std::vector < Node* > > board) {


		if (isEmpty(board)) {
			return Node::STATES::X;
		}

		int xCounter = 0;
		int oCounter = 0;

		for (std::vector < Node* > v : board) {

			for (Node* n : v) {

				if ((n->value == Node::STATES::X)) {
					xCounter++;
				}

				if ((n->value == Node::STATES::O)) {
					oCounter++;
				}
			}

		}

		if (xCounter <= oCounter) {
			return Node::STATES::X;
		}

		if (oCounter < xCounter) {
			return Node::STATES::O;
		}
	}

	Board::Board() {

		for (int x = 0; x < SIZE; x++ ) {
		
			for (int y = 0; y < SIZE; y++) {

				Node* toAdd = new Node(x,y);
				(*board)[x][y] = toAdd;

			}
		
		}

	}

	bool Board::isEmpty( const std::vector< std::vector < Node* > > &board) {

		for (std::vector < Node* > v : board) {

			for (Node* n : v) {

				if (!(n->value == Node::STATES::N)) {
					return false;
				}

			}

		 }

		return true;
	}

	std::vector< std::vector < Node* > > Board::play(std::pair<int, int> cord, std::vector< std::vector < Node* > > *board) {

		if ((*board)[cord.first][cord.second]->value == Node::STATES::N) {
			(*board)[cord.first][cord.second]->value = getNextPlayer(*board);
		}
		return *board;
	}

	std::vector< std::pair<int, int> > Board::getFrees(std::vector< std::vector < Node* > > board) {

		std::vector< std::pair<int, int> > ret;

		for (std::vector < Node* > v : board) {

			for (Node* n : v) {

				if (n->value == Node::STATES::N) {
					ret.push_back(n->cord);
				}

			}

		}
		return ret;

	}

	void Board::printBoard(std::vector< std::vector < Node* > > &board){

		for (std::vector < Node* > v : board) {

			for (Node* n : v) {

				if (n->value == Node::STATES::N) {
					std::cout << "  ";
				}

				else if (n->value == Node::STATES::X) {
					std::cout << "X ";
				}

				else if (n->value == Node::STATES::O) {
					std::cout << "O ";
				}


			}
			std::cout << std::endl;
		}

	}
	bool Board::isFull(std::vector< std::vector < Node* > >& board) {

		for (std::vector < Node* > v : board) {

			for (Node* n : v) {

				if (n->value == Node::STATES::N) {
					return false;
				}
			}
		}

		return true;
	}

	Node::STATES Board::calculateWinner(std::vector< std::vector < Node* > >& board) {

		//Diagonais

		if (board[1][1]->value != Node::STATES::N && ((board[0][0]->value == board[1][1]->value && board[0][0]->value == board[2][2]->value)
			|| (board[0][2]->value == board[1][1]->value && board[0][2]->value == board[2][0]->value))
			) {
			return board[1][1]->value;
		}

		//Horizontais
		for (int x = 0; x < SIZE; x++) {

			if (board[x][0]->value == board[x][1]->value && board[x][0]->value == board[x][2]->value && board[x][0]->value != Node::STATES::N) {
				return board[x][0]->value;
			}

		}

		//Verticais
		for (int x = 0; x < SIZE; x++) {

			if (board[0][x]->value == board[1][x]->value && board[0][x]->value == board[2][x]->value && board[0][x]->value != Node::STATES::N) {
				return board[0][x]->value;
			}

		}

		return Node::STATES::N;
	}