#include "Board.h"

bool Board::isEmpty(const Matrix &board) {

  for (std::vector<Node *> v : board) {

    for (Node *n : v) {

      if (!(n->value == Node::STATES::N)) {
        return false;
      }
    }
  }

  return true;
}

Matrix Board::play(std::pair<int, int> cord, Matrix *board,
                   Node::STATES player) {
  if ((*board)[cord.first][cord.second]->value == Node::STATES::N) {
    (*board)[cord.first][cord.second]->value = player;
  }
  return *board;
}

std::vector<std::pair<int, int>> Board::getFrees(Matrix board) {

  std::vector<std::pair<int, int>> ret;

  for (std::vector<Node *> v : board) {

    for (Node *n : v) {

      if (n->value == Node::STATES::N) {
        ret.push_back(n->cord);
      }
    }
  }
  return ret;
}

void Board::printBoard(Matrix &board) {

  for (std::vector<Node *> v : board) {

    for (Node *n : v) {

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
bool Board::isFull(Matrix &board) {

  for (std::vector<Node *> v : board) {

    for (Node *n : v) {

      if (n->value == Node::STATES::N) {
        return false;
      }
    }
  }

  return true;
}

Node::STATES Board::calculateWinner(Matrix &board) {

  // Diagonais

  if (board[1][1]->value != Node::STATES::N &&
      ((board[0][0]->value == board[1][1]->value &&
        board[0][0]->value == board[2][2]->value) ||
       (board[0][2]->value == board[1][1]->value &&
        board[0][2]->value == board[2][0]->value))) {
    return board[1][1]->value;
  }

  // Horizontais
  for (int x = 0; x < SIZE; x++) {

    if (board[x][0]->value == board[x][1]->value &&
        board[x][0]->value == board[x][2]->value &&
        board[x][0]->value != Node::STATES::N) {
      return board[x][0]->value;
    }
  }

  // Verticais
  for (int x = 0; x < SIZE; x++) {

    if (board[0][x]->value == board[1][x]->value &&
        board[0][x]->value == board[2][x]->value &&
        board[0][x]->value != Node::STATES::N) {
      return board[0][x]->value;
    }
  }

  return Node::STATES::N;
}

Board::Board() {
  for (int x = 0; x < SIZE; x++) {
    for (int y = 0; y < SIZE; y++) {
      Node *toAdd = new Node(x, y);
      (*board)[x][y] = toAdd;
    }
  }
}
