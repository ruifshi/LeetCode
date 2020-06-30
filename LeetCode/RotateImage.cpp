#include "stdafx.h"
#include "RotateArray.h"

void rotate(vector<vector<int>>& matrix) {
  //transpose - flip over diagonal
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = i; j < matrix[0].size(); j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  // reverse the matrix rows to get everything in place
  for (int i = 0; i < matrix.size(); i++) {
    reverse(matrix[i].begin(), matrix[i].end());
  }
}