#include <cstdlib>
#include <iostream>

#include "Board.h"
#include "Bot.h"
#include "Node.h"
#include <chrono>
#include <thread>

void clean() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void printUsage(const char *programName) {
  std::cout << "Usage: " << programName << " [option]" << std::endl;
  std::cout << "Options:" << std::endl;
  std::cout << "  -x    Play as X (default)" << std::endl;
  std::cout << "  -o    Play as O (bot starts)" << std::endl;
  std::cout << "  -b    Bot vs Bot" << std::endl;
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

int botgame(Board &game) {
  Bot b1(Node::STATES::O);
  Bot b2(Node::STATES::X);
  while (true) {
    clean();
    Board::printBoard(*game.board);

    checkWinner(game);

    b1.organizePlay(game);
    checkWinner(game);
    b2.organizePlay(game);

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
}

int main(int argc, char *argv[]) {

  Board game;
  Node::STATES player = Node::STATES::X;

  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "-x") {
      player = Node::STATES::X;
      break;
    } else if (arg == "-o") {
      player = Node::STATES::O;
      break;
    } else if (arg == "-b") {
      return botgame(game); // Bot vs Bot mode

    } else {
      printUsage(argv[0]);
      return 1;
    }
  }

  // normal bot vs player mode
  Node::STATES botSymbol =
      (player == Node::STATES::X) ? Node::STATES::O : Node::STATES::X;
  int x;
  Bot bot(botSymbol);

  if (player == Node::STATES::O) {
    bot.organizePlay(game); // Bot starts
  }
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
        Board::play({line, row}, game.board, player);
        checkWinner(game);
        bot.organizePlay(game);
      } else {
        continue;
      }
    }
  }

  return 0;
}
