#include "Bot.h"
#include <algorithm>
#include <limits>

static void freeMatrix(Matrix &matrix) {
  for (auto &row : matrix)
    for (Node *n : row)
      delete n;
  matrix.clear();
}

void Bot::organizePlay(Board &board) {
  Matrix *table = board.board;
  std::vector<std::pair<int, int>> possibles = Board::getFrees(*table);

  std::vector<std::pair<std::pair<int, int>, int>> choose;

  // If we're going first or second, prioritize the center or corners
  if (justOne(*table) || Board::getFrees(*table).size() >= 7) {
    // Try to take center first
    for (const auto &play_ : possibles) {
      if (play_.first == 1 && play_.second == 1) {
        Board::play(play_, table, Node::STATES::O);
        return;
      }
    }
    // Then try corners
    for (const auto &play_ : possibles) {
      if ((play_.first == 0 && play_.second == 0) ||
          (play_.first == 0 && play_.second == 2) ||
          (play_.first == 2 && play_.second == 0) ||
          (play_.first == 2 && play_.second == 2)) {
        Board::play(play_, table, Node::STATES::O);
        return;
      }
    }
  }

  // Check for immediate win for O
  for (const auto &play_ : possibles) {
    Matrix copied = copyBoard(*table);
    Board::play(play_, &copied, Node::STATES::O);
    if (Board::calculateWinner(copied) == Node::STATES::O) {
      Board::play(play_, table, Node::STATES::O);
      freeMatrix(copied);
      return;
    }
    freeMatrix(copied);
  }

  // Check for immediate block needed
  for (const auto &play_ : possibles) {
    Matrix copied = copyBoard(*table);
    Board::play(play_, &copied, Node::STATES::X);
    if (Board::calculateWinner(copied) == Node::STATES::X) {
      Board::play(play_, table, Node::STATES::O);
      freeMatrix(copied);
      return;
    }
    freeMatrix(copied);
  }

  int bestScore = std::numeric_limits<int>::max();
  std::pair<int, int> bestPlay = possibles[0]; // Default to first move

  for (const auto &play_ : possibles) {
    Matrix copied = copyBoard(*table);
    Board::play(play_, &copied, Node::STATES::O);

    int score = maxValue(copied, 0);

    if (score < bestScore) {
      bestScore = score;
      bestPlay = play_;
    }

    freeMatrix(copied);
  }

  Board::play(bestPlay, table, Node::STATES::O);
}

Matrix Bot::copyBoard(const Matrix &board) {
  Matrix ret(SIZE, std::vector<Node *>(SIZE, nullptr));
  for (int x = 0; x < SIZE; ++x) {
    for (int y = 0; y < SIZE; ++y) {
      Node *toAdd = new Node(x, y);
      toAdd->value = board[x][y]->value;
      ret[x][y] = toAdd;
    }
  }
  return ret;
}

int Bot::minValue(Matrix &board, int depth) {
  // Terminal state checks
  auto winner = Board::calculateWinner(board);
  if (winner == Node::STATES::O)
    return -10 + depth; // good
  if (winner == Node::STATES::X)
    return 10 - depth; // bad
  if (Board::isFull(board))
    return 0; // Draw

  int minVal = std::numeric_limits<int>::max();
  for (const auto &play : Board::getFrees(board)) {
    Matrix copied = copyBoard(board);
    Board::play(play, &copied, Node::STATES::O);
    int temp = maxValue(copied, depth + 1);
    minVal = std::min(minVal, temp);
    freeMatrix(copied);
  }

  return minVal;
}

int Bot::maxValue(Matrix &board, int depth) {
  // Terminal state checks
  auto winner = Board::calculateWinner(board);
  if (winner == Node::STATES::O)
    return -10 + depth; // bad
  if (winner == Node::STATES::X)
    return 10 - depth; // good
  if (Board::isFull(board))
    return 0; // Draw

  int maxVal = std::numeric_limits<int>::min();
  for (const auto &play : Board::getFrees(board)) {
    Matrix copied = copyBoard(board);
    Board::play(play, &copied, Node::STATES::X);
    int temp = minValue(copied, depth + 1);
    maxVal = std::max(maxVal, temp);
    freeMatrix(copied);
  }

  return maxVal;
}

bool Bot::justOne(const Matrix &board) {
  int count = 0;
  for (const auto &row : board) {
    for (const Node *n : row) {
      if (n->value != Node::STATES::N)
        count++;
    }
  }
  return count <= 1;
}

int Bot::getMax(int a, int b) { return std::max(a, b); }

int Bot::getMin(int a, int b) { return std::min(a, b); }
