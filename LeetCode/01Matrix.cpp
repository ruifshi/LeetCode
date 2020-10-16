#include "stdafx.h"
#include "01Matrix.h"

#include <queue>

//we should start from "0", and change "1" to INT_MAX in our original matrix.
vector<vector<int>> Solution::updateMatrix(vector<vector<int>>& matrix) {
  if (matrix.empty()) return matrix;
  int m = matrix.size();
  int n = matrix[0].size();
  queue<pair<int, int>> zeros;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (matrix[i][j] == 0) {
        zeros.push({ i,j });
      }
      else {
        matrix[i][j] = INT_MAX;
      }
    }
  }

  vector<vector<int>> dir = { {1,0},{-1,0},{0,1},{0,-1} };

  while (!zeros.empty()) {
    int i = zeros.front().first, j = zeros.front().second;
    zeros.pop();

    for (auto d : dir) {
      int ii = i + d[0], jj = j + d[1];
      if (ii < m && ii >= 0 && jj < n && jj >= 0) {
        if (matrix[ii][jj] >= matrix[i][j] + 1) {
          matrix[ii][jj] = matrix[i][j] + 1;
          zeros.push({ ii,jj });
        }
      }
    }
  }
  return matrix;
}