#include "stdafx.h"
#include "LongestIncreasingPathInAMatrix.h"

#include <algorithm>

int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& memo) {
  if (memo[i][j] != 0) return memo[i][j];

  vector<vector<int>> dirs { {0, 1}, { 1,0 }, { 0,-1 }, { -1,0 } };
  for (auto dir : dirs) {
    int i2 = i + dir[0];
    int j2 = j + dir[1];
    
    // check bounds + increasing
    if (i2 >= 0 && i2 < matrix.size() && j2 >= 0 && j2 < matrix[0].size() &&
        matrix[i2][j2] > matrix[i][j]) {
      memo[i][j] = max(memo[i][j], dfs(matrix, i2, j2, memo));
    }
  }

  return memo[i][j]++;
}

int Solution::longestIncreasingPath(vector<vector<int>>& matrix) {
  if (matrix.size() == 0) return 0;

  // the max number of increasing from other paths to this value
  vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), 0));
  int count = 0;

  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      count = max(count, dfs(matrix, i, j, memo));
    }
  }

  return count;
}