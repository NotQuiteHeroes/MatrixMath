#include "matrixMath.h"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

MatrixMath::MatrixMath() { clearAll(); }

// Given vectors A and B of the form {x, y, z}
// Adds: Ax+Bx, Ay+By, Az + Bz
// Answer is vector of form {x, y, z}
void MatrixMath::add() {
  answerVector.push_back(firstVector[0] + secondVector[0]);
  answerVector.push_back(firstVector[1] + secondVector[1]);
  answerVector.push_back(firstVector[2] + secondVector[2]);

  // Use 1 to clarify to displayAnswer that the answer is a vector
  displayAnswer(1);
}

// Given vectors A and B of the form {x, y, z}
// Subtracts: Ax-Bx, Ay-By, Az-Bz
// Answer is vector of form {x, y, z}
void MatrixMath::subtract() {
  answerVector.push_back(firstVector[0] - secondVector[0]);
  answerVector.push_back(firstVector[1] - secondVector[1]);
  answerVector.push_back(firstVector[2] - secondVector[2]);

  // Use 1 to clarify to displayAnswer that answer is a vector
  displayAnswer(1);
}

// Given vectors A and B of the form {x, y, z}
// Multiplies: Ax*Bx, Ay*By, Az*Bz
// Sums result of each individual multiplication
// Answer is single integer
void MatrixMath::dotProduct() {
  scalarProduct += firstVector[0] * secondVector[0];
  scalarProduct += firstVector[1] * secondVector[1];
  scalarProduct += firstVector[2] * secondVector[2];

  // Use 2 to clarify to displayAnswer that the answer is an integer
  displayAnswer(2);
}

// Given vectors A and B of the form {x, y, z}
// Multiplies and subtracts:
// i = (Ay*Bz) - (Az * By)
// j = (Az * Bx) - (Ax * Bz)
// k = (Ax * By) - (Ay * Bx)
// Answer is vector of form {i, j, k}
void MatrixMath::crossProduct() {
  int i, j, k;

  i = (firstVector[1] * secondVector[2]) - (firstVector[2] * secondVector[1]);
  j = (firstVector[2] * secondVector[0]) - (firstVector[0] * secondVector[2]);
  k = (firstVector[0] * secondVector[1]) - (firstVector[1] * secondVector[0]);

  answerVector.push_back(i);
  answerVector.push_back(j);
  answerVector.push_back(k);

  // Use 1 to clarify to displayAnswer that the answer is a vector
  displayAnswer(1);
}

// Note that matrix must have same number of columns as vector has rows
// Given vector A of form {x, y, z} and matrix B of form {a, b, c},{d, e,
// f},{ g, h, o }
// Multiplies and adds:
// i = (a * x) + (b * y) + (c * z)
// j = (d * x) + (e * y) + (f * z)
// k = (g * x) + ( h * y) + (i * z)
// Answer is vector of form {i, j, k}
void MatrixMath::vectorXmatrix() {
  int i, j, k;

  i = (firstMatrix[0][0] * firstVector[0]) +
      (firstMatrix[0][1] * firstVector[1]) +
      (firstMatrix[0][2] * firstVector[2]);
  j = (firstMatrix[1][0] * firstVector[0]) +
      (firstMatrix[1][1] * firstVector[1]) +
      (firstMatrix[1][2] * firstVector[2]);
  k = (firstMatrix[2][0] * firstVector[0]) +
      (firstMatrix[2][1] * firstVector[1]) +
      (firstMatrix[2][2] * firstVector[2]);

  answerVector.push_back(i);
  answerVector.push_back(j);
  answerVector.push_back(k);

  // Use 1 to clarify to displayAnswer that the answer is a vector
  displayAnswer(1);
}

// Note that matrix A must have same number of columns as matrix B has rows
// Given matrix A and B of form{a1, a2, a3, a4},{b1, b2,
// b3, b4},{c1, c2, c3, c4}, {d1, d2, d3, d4}
// Multiplies and adds: (shortened with loops in code for brevity's sake)
// First row of answer Matrix
// a = (Aa1 * Ba1) + (Aa2 * Bb1) + (Aa3 * Bc1) + (Aa4 * Bd1)
// b = (Aa1 * Ba2) + (Aa2 * Bb2) + (Aa3 * Bc2) + (Aa4 * Bd2)
// c = ((Aa1 * Ba3) + (Aa2 * Bb3) + (Aa3 * Bc3) + (Aa4 * Bd3)
// d = (Aa1 * Ba4) + (Aa2 * Bb4) + (Aa3 * Bc4) + (Aa4 * Bd4)
// Continue in this manner for Ab, Ac, and Ad for additional rows
// answer is form of 4x4 matrix
void MatrixMath::matrixX() {
  int sum = 0;

  for (int i = 0;i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      sum = 0;
      for (int k = 0; k < 4; ++k) {
        answerMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
      }
    }
  }

  // Use 3 to clarify to displayAnswer that the answer is a matrix
  displayAnswer(3);
}

void MatrixMath::displayAnswer(int type) {
  std::cout << "Answer:" << std::endl;
  switch (type) {
  case 1:
    std::cout << "{" << answerVector[0] << "," << answerVector[1] << ","
              << answerVector[2] << "}" << std::endl;
    break;
  case 2:
    std::cout << scalarProduct << std::endl;
    break;
  case 3:
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        std::cout << answerMatrix[i][j] << " ";
      }
      std::cout << std::endl;
    }
    break;
  }
}

void MatrixMath::setVectors(int amount) {
  std::string vectorOne, vectorTwo;
  std::cout << "Enter the vector's elements on one line, separated by commas"
            << std::endl;
  std::cout << "Press Enter when done." << std::endl;
  std::cout << "First Vector: " << std::endl;
  std::getline(std::cin, vectorOne);

  if (amount == 2) {
    std::cout << "Second Vector: " << std::endl;
    std::getline(std::cin, vectorTwo);
  }

  std::stringstream ssOne(vectorOne);
  std::stringstream ssTwo(vectorTwo);
  int i, j;

  while (ssOne >> i) {
    firstVector.push_back(i);

    if (ssOne.peek() == ',' || ssOne.peek() == ' ') {
      ssOne.ignore();
    }
  }

  if (amount == 2) {
    while (ssTwo >> j) {
      secondVector.push_back(j);

      if (ssTwo.peek() == ',' || ssTwo.peek() == ' ') {
        ssTwo.ignore();
      }
    }
  }
}

void MatrixMath::setMatrices(int amount, int columns) {
  std::string vectorOne, vectorTwo, vectorThree, vectorFour;
  std::string vectorFive, vectorSix, vectorSeven, vectorEight;

  std::cout << "Enter the matrix's elements one row at a time. Separate "
               "numbers in the same row by commas."
            << std::endl;
  std::cout << "Press Enter when done with each row." << std::endl;

  std::cout << "First Matrix: " << std::endl;
  std::cout << "First row: " << std::endl;
  std::getline(std::cin, vectorOne);

  std::cout << "Second row: " << std::endl;
  std::getline(std::cin, vectorTwo);

  std::cout << "Third row: " << std::endl;
  std::getline(std::cin, vectorThree);

  if (columns == 4) {
    std::cout << "Fourth row: " << std::endl;
    std::getline(std::cin, vectorFour);
  }
  if (amount == 2) {
    std::cout << "Second Matrix: " << std::endl;
    std::cout << "First row: " << std::endl;
    std::getline(std::cin, vectorFive);

    std::cout << "Second row: " << std::endl;
    std::getline(std::cin, vectorSix);

    std::cout << "Third row: " << std::endl;
    std::getline(std::cin, vectorSeven);

    if (columns == 4) {
      std::cout << "Fourth row: " << std::endl;
      std::getline(std::cin, vectorEight);
    }
  }

  std::stringstream ssOne(vectorOne);
  std::stringstream ssTwo(vectorFive);
  int i, j, k, l, m, n, o, p;
  std::vector<int> temp;

  while (ssOne >> i) {
    temp.push_back(i);

    if (ssOne.peek() == ',' || ssOne.peek() == ' ') {
      ssOne.ignore();
    }
  }

  firstMatrix.push_back(temp);
  ssOne.clear();
  ssOne.str("");
  temp.clear();

  ssOne.str(vectorTwo);

  while (ssOne >> j) {
    temp.push_back(j);

    if (ssOne.peek() == ',' || ssOne.peek() == ' ') {
      ssOne.ignore();
    }
  }

  firstMatrix.push_back(temp);
  ssOne.clear();
  ssOne.str("");
  temp.clear();

  ssOne.str(vectorThree);

  while (ssOne >> k) {
    temp.push_back(k);

    if (ssOne.peek() == ',' || ssOne.peek() == ' ') {
      ssOne.ignore();
    }
  }

  firstMatrix.push_back(temp);
  ssOne.clear();
  ssOne.str("");
  temp.clear();

  if (columns == 4) {
    ssOne.str(vectorFour);
    while (ssOne >> l) {
      temp.push_back(l);

      if (ssOne.peek() == ',' || ssOne.peek() == ' ') {
        ssOne.ignore();
      }
    }

    firstMatrix.push_back(temp);
  }

  if (amount == 2) {
    temp.clear();
    while (ssTwo >> m) {
      temp.push_back(m);

      if (ssTwo.peek() == ',' || ssTwo.peek() == ' ') {
        ssTwo.ignore();
      }
    }

    secondMatrix.push_back(temp);
    ssTwo.clear();
    ssTwo.str("");
    temp.clear();

    ssTwo.str(vectorSix);

    while (ssTwo >> n) {
      temp.push_back(n);

      if (ssTwo.peek() == ',' || ssTwo.peek() == ' ') {
        ssTwo.ignore();
      }
    }

    secondMatrix.push_back(temp);
    ssTwo.clear();
    ssTwo.str("");
    temp.clear();

    ssTwo.str(vectorSeven);

    while (ssTwo >> o) {
      temp.push_back(o);

      if (ssTwo.peek() == ',' || ssTwo.peek() == ' ') {
        ssTwo.ignore();
      }
    }

    secondMatrix.push_back(temp);
    ssTwo.clear();
    ssTwo.str("");
    temp.clear();

    if (columns == 4) {
      ssTwo.str(vectorEight);
      while (ssTwo >> p) {
        temp.push_back(p);

        if (ssTwo.peek() == ',' || ssTwo.peek() == ' ') {
          ssTwo.ignore();
        }
      }

      secondMatrix.push_back(temp);
    }
  }
}

void MatrixMath::clearAll() {
  firstVector.clear();
  secondVector.clear();
  firstMatrix.clear();
  secondMatrix.clear();

  answerVector.clear();
  for(int i = 0; i < 4; i++){
    for(int j = 0; j <4; j++){
      answerMatrix[i][j] = 0;
    }
  }
  scalarProduct = 0;
}
