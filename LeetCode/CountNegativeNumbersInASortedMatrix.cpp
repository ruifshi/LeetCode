#include "stdafx.h"
#include "CountNegativeNumbersInASortedMatrix.h"

/*
One optimization is to count from right to left and break when we encounter a non-negative.

Another optimization is to process rows from bottom and stop when the last element in the row is non-negative.
*/
int countNegatives(vector<vector<int>>& grid) {
  int res = 0;
  for (int i = grid.size() - 1; i >= 0 && grid[i].back() < 0; --i)
    for (int j = grid[i].size() - 1; j >= 0 && grid[i][j] < 0; --j)
      ++res;
  return res;
}