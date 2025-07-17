#include <cstdlib>
#include <iostream>

#include "Board.h"
#include "Bot.h"
#include "Node.h"

void clean() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void checkWinner(Board &game) {
  Node::STATES winner = Board::calculateWinner(*game.board);
  if (winner != Node::STATES::N) {
    clean();
    Board::printBoard(*game.board);
    if (winner == Node::STATES::X) {
      std::cout << "Player X wins!" << std::endl;
    } else {
      std::cout << "Player O wins!" << std::endl;
    }
    exit(0);
  } else if (Board::isFull(*game.board)) {
    clean();
    Board::printBoard(*game.board);
    std::cout << "It's a draw!" << std::endl;
    exit(0);
  }
}
int main() {

  Board game;
  int x;

  while (true) {
    checkWinner(game);

    clean();

    Board::printBoard(*game.board);

    std::cout << "Move: (1-9) " << std::endl;

    std::cin >> x;

    if (x >= 1 && x <= SIZE * SIZE) {
      int line, row;
      // convert x to line and row
      line = (x - 1) / SIZE;
      row = (x - 1) % SIZE;
      if ((game.board)->at(line).at(row)->value == Node::STATES::N) {
        Board::play({line, row}, game.board);
        checkWinner(game);
        Bot::organizePlay(game);
      } else {
        continue;
      }
    }
  }

  return 0;
}
