#include "stdafx.h"
#include "ToeplitzMatrix.h"

bool Solution::isToeplitzMatrix(vector<vector<int>>& matrix) {
  for (int row = 1; row < matrix.size(); row++) { // compare all diagonals
    for (int col = 1; col < matrix[0].size(); col++) {
      if (matrix[row - 1][col - 1] != matrix[row][col]) {
        return false;
      }
    }
  }

  return true;
}