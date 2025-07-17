#ifndef BOT_H
#define BOT_H

#include "Board.h"
#include "Node.h"
#include <vector>

typedef std::vector<std::vector<Node *>> Matrix;

class Bot {
private:
  static bool justOne(const Matrix &board);

public:
  static void organizePlay(Board &board);
  static Matrix copyBoard(const Matrix &board);
  static int minValue(Matrix &board, int depth = 0);
  static int maxValue(Matrix &board, int depth = 0);
  static int getMax(int a, int b);
  static int getMin(int a, int b);
};

#endif
