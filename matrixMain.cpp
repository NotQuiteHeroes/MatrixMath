#include "matrixMath.h"
#include <iostream>
#include <limits>
#include <locale>
#include <string>
#include <vector>

using namespace std;

int menuSelection();
void operationHandler(int operationType, MatrixMath matrixMath);

MatrixMath matrixMath;

int main() {
  char answer;

  cout << "Welcome to Matrix Math!" << endl;
  int selection = menuSelection();
  operationHandler(selection, matrixMath);

  cout << "Would you like to perform another operation?" << endl;
  cout << "Enter y or n" << endl;
  cin >> answer;
  while (tolower(answer) != 'y' && tolower(answer) != 'n') {
    cout << "Invalid selection, please enter y or n." << endl;
    cin >> answer;
  }

  if (tolower(answer) == 'y') {
    matrixMath.clearAll();
    main();
  }

  return 0;
}

int menuSelection() {
  int selection;
  cout << "Which operation would you like to perform?" << endl;
  cout << "1. Vector Addition" << endl;
  cout << "2. Vector Subtraction" << endl;
  cout << "3. Vector Dot Product" << endl;
  cout << "4. Vector Cross Product" << endl;
  cout << "5. Vector x Matrix" << endl;
  cout << "6. Matrix Dot Product" << endl;
  cin >> selection;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  while (selection < 1 || selection > 7) {
    cout << "Invalid. Please enter a number between 1 and 7" << endl;
    cin >> selection;
  }

  return selection;
}

void operationHandler(int operationType, MatrixMath matrixMath) {
  switch (operationType) {
  case 1:
    matrixMath.setVectors();
    matrixMath.add();
    break;
  case 2:
    matrixMath.setVectors();
    matrixMath.subtract();
    break;
  case 3:
    matrixMath.setVectors();
    matrixMath.dotProduct();
    break;
  case 4:
    matrixMath.setVectors();
    matrixMath.crossProduct();
    break;
  case 5:
    matrixMath.setVectors(1);
    matrixMath.setMatrices(1, 3);
    matrixMath.vectorXmatrix();
    break;
  case 6:
    matrixMath.setMatrices();
    matrixMath.matrixX();
    break;
  default:
    main();
  }
}
