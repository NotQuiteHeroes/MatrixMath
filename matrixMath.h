#ifndef _MATRIXMATH_
#define _MATRIXMATH_

#include <vector>

class MatrixMath {
public:
  MatrixMath();
  void add();
  void subtract();
  void dotProduct();
  void crossProduct();
  void vectorXmatrix();
  void matrixX();
  void displayAnswer(int type);
  void setVectors(int amount = 2);
  void setMatrices(int amount = 2, int columns = 4);
  void clearAll();

private:
  std::vector<int> firstVector;
  std::vector<int> secondVector;
  std::vector<std::vector<int> > firstMatrix;
  std::vector<std::vector<int> > secondMatrix;
  std::vector<int> answerVector;
  int answerMatrix[4][4];
  int scalarProduct;
};

#endif
