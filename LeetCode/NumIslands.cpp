#include "stdafx.h"
#include "NumIslands.h"

void dfs(vector<vector<char>>& grid, int i, int j) {
  if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '2') {
    return;
  }

  if (grid[i][j] != '2' && grid[i][j] == '1') {
    grid[i][j] = '2';
    dfs(grid, i + 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i - 1, j);
    dfs(grid, i, j - 1);
  }
}

int Solution::numIslands(vector<vector<char>>& grid) {
  if (grid.size() == 0) return 0;
  if (grid[0].size() == 0) return 0;

  int count = 0;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (grid[i][j] != '2' && grid[i][j] == '1')
        count++;
      dfs(grid, i, j);
    }
  }

  return count;
}