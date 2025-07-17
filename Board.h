#include <iostream>
#include <vector>

#include "Node.h"

#ifndef BOARD_H
#define BOARD_H

#define SIZE 3

typedef std::vector<std::vector<Node *>> Matrix;

class Board {

public:
  Matrix *board = new Matrix(SIZE, std::vector<Node *>(SIZE, nullptr));

  Board();

  bool static isEmpty(const Matrix &board);

  Matrix static play(std::pair<int, int> cord, Matrix *board,
                     Node::STATES player = Node::STATES::X);

  std::vector<std::pair<int, int>> static getFrees(Matrix board);

  void static printBoard(Matrix &board);

  Node::STATES static calculateWinner(Matrix &board);

  bool static isFull(Matrix &board);
};

#endif
