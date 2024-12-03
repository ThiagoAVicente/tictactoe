#include "Bot.h"

	void Bot::organizePlay(Board board) {

		std::vector< std::vector < Node* > >* table = board.board;

		//BOT plays second
		std::vector<std::pair<int, int>> possibles = Board::getFrees(*table);

		bool srt = false;

		if (justOne(*table)) {
			srt = true;
			std::random_device rd; // Obtain a random number from hardware
			std::mt19937 rng(rd()); // Seed the generator

			std::shuffle(possibles.begin(), possibles.end(), rng);

			possibles = std::vector<std::pair<int, int>>(possibles.begin(), possibles.begin() + 4);
		}

		std::vector < std::pair < std::pair<int, int>, int> > choose;

		for (std::pair<int, int> play_ : possibles) {
			std::vector< std::vector < Node* > >* copied = copyBoard(*table);

			Board::play(play_, copied);
			int temp = minValue(copied, srt);
			
			for (std::vector < Node* > v : *copied) {

				for (Node* n : v) {
					delete n;
				}

			}
			delete copied;
			choose.push_back({ play_, temp });
		}

		int min = 100;
		std::pair<int, int> play;

		for (std::pair<std::pair<int, int>, int> item : choose) {

			if (item.second < min) {
				min = item.second;
				play = item.first;
			}
		}

		Board::play(play, table);
		return;

	}

	std::vector< std::vector < Node* > >* Bot::copyBoard(std::vector< std::vector < Node* > >& board) {

		std::vector< std::vector < Node* > >* ret = new std::vector< std::vector < Node* > >(SIZE, std::vector<Node*>(SIZE, nullptr));

		for (int x = 0; x < SIZE; x++) {

			for (int y = 0; y < SIZE; y++) {

				Node* toAdd = new Node(x, y);
				toAdd->value = board[x][y]->value;
				(*ret)[x][y] = toAdd;

			}
		}

		return ret;

	}

	int Bot::minValue(std::vector<std::vector<Node*>>* board, bool srt) {

		if (Board::isFull(*board)) {
			return 0;
		}

		if (Board::calculateWinner(*board) == Node::STATES::O) {
			return -1;
		}

		std::vector<std::pair<int, int>> possibles = Board::getFrees(*board);

		if (srt && possibles.size() > SIZE) {
			std::random_device rd;
			std::mt19937 rng(rd());

			std::shuffle(possibles.begin(), possibles.end(), rng);

			possibles = std::vector<std::pair<int, int>>(possibles.begin(), possibles.begin() + 2);
		}

		int minVal = 100; // Initialize to a large value

		for (const std::pair<int, int>& play : possibles) {
			std::vector<std::vector<Node*>>* copied = copyBoard(*board);
			Board::play(play, copied);

			int temp = maxValue(copied, srt);
			minVal = getMin(minVal, temp);
			delete copied;
		}

		return minVal;
	}

	int Bot::maxValue(std::vector<std::vector<Node*>>* board, bool srt) {

		if (Board::calculateWinner(*board) == Node::STATES::X) {
			return 1;
		}

		if (Board::isFull(*board)) {
			return 0;
		}

		std::vector<std::pair<int, int>> possibles = Board::getFrees(*board);
		if (srt && possibles.size() > SIZE) {
			std::random_device rd; // Obtain a random number from hardware
			std::mt19937 rng(rd()); // Seed the generator

			std::shuffle(possibles.begin(), possibles.end(), rng);

			possibles = std::vector<std::pair<int, int>>(possibles.begin(), possibles.begin() + 2);
		}
		int maxVal = -100; // Initialize to a small value

		for (const std::pair<int, int>& play : possibles) {
			std::vector<std::vector<Node*>>* copied = copyBoard(*board);
			Board::play(play, copied);

			int temp = minValue(copied,srt);
			maxVal = getMax(maxVal, temp );
			delete copied;
		}

		return maxVal;
	}

	bool Bot::justOne(std::vector< std::vector < Node* > > board) {
		int count = 1;

		for (std::vector < Node* > v : board) {

			for (Node* n : v) {

				if (!(n->value == Node::STATES::N)) {
					count--;
				}
				if (count < 0 ) {
					return false;
				}

			}

		}
		return true;
	}

	int Bot::getMax(int a, int b) {

		if (a > b) {
			return a;
		}
		return b;
	}

	int Bot::getMin(int a, int b) {

		if (b > a) {
			return a;
		}
		return b;
	}
