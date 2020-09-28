#include "stdafx.h"
#include "MaximalSquare.h"

#include <algorithm>

/*
To appy DP, we define the state as the maximal size (square = size * size) of the square that can be formed till point (i, j), denoted as dp[i][j].

For the topmost row (i = 0) and the leftmost column (j = 0), we have dp[i][j] = matrix[i][j] - '0', meaning that it can at most form a square of size 1 when the matrix has a '1' in that cell.

When i > 0 and j > 0, if matrix[i][j] = '0', then dp[i][j] = 0 since no square will be able to contain the '0' at that cell. If matrix[i][j] = '1', we will have dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1, which means that the square will be limited by its left, upper and upper-left neighbors.
*/
int Solution::maximalSquare(vector<vector<char>>& matrix) {
  if (matrix.empty()) {
    return 0;
  }
  int m = matrix.size(), n = matrix[0].size(), sz = 0;
  vector<vector<int>> dp(m, vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!i || !j || matrix[i][j] == '0') {
        dp[i][j] = matrix[i][j] - '0';
      }
      else {
        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
      }
      sz = max(dp[i][j], sz);
    }
  }
  return sz * sz;
}

/*
public class Solution {
    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length, cols = rows > 0 ? matrix[0].length : 0;
        int maxsqlen = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    int sqlen = 1;
                    boolean flag = true;
                    while (sqlen + i < rows && sqlen + j < cols && flag) {
                        for (int k = j; k <= sqlen + j; k++) {
                            if (matrix[i + sqlen][k] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        for (int k = i; k <= sqlen + i; k++) {
                            if (matrix[k][j + sqlen] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        if (flag)
                            sqlen++;
                    }
                    if (maxsqlen < sqlen) {
                        maxsqlen = sqlen;
                    }
                }
            }
        }
        return maxsqlen * maxsqlen;
    }
}
*/