#include <iostream>
#include <cstdlib>

#include "Board.h"
#include "Bot.h"
#include "Node.h"

int main() {

	Board game;

	int x, y;

	while (true) {
		system("cls");

		Board::printBoard(*game.board);

		Node::STATES winner = Board::calculateWinner(*game.board);
		if (winner == Node::STATES::X) {
			std::cout << "Winner!" << std::endl;
			exit(0);
		}
		if (winner == Node::STATES::O) {
			std::cout << "Loser!" << std::endl;
			exit(0);
		}
		if (Board::isFull(*game.board)) {
			std::cout << "Tie" << std::endl;
			exit(0);
		}

		
		std::cout << "Move: " << std::endl;
		
		std::cin >> x;
		std::cin >> y;

		if (x >= 0 && x < SIZE && y >= 0 && y < SIZE ) {
			if ((game.board)->at(x).at(y)->value == Node::STATES::N) {
				Board::play({ x,y },game.board );
				Bot::organizePlay(game);
			}
			else {
				continue;
			}

		}



	}


	return 0;
}