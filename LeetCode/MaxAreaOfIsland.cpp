#include "stdafx.h"
#include "MaxAreaOfIsland.h"

#include <algorithm>

int maxAreaOfIslandHelper(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
  if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || visited[i][j]) {
    return 0;
  }

  visited[i][j] = true;

  // add current square and visited all attached
  return 1 + maxAreaOfIslandHelper(grid, visited, i + 1, j) +
             maxAreaOfIslandHelper(grid, visited, i, j + 1) +
             maxAreaOfIslandHelper(grid, visited, i - 1, j) +
             maxAreaOfIslandHelper(grid, visited, i, j - 1);
}

int Solution::maxAreaOfIsland(vector<vector<int>>& grid) {
  if (grid.size() == 0) return 0;

  vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
  int ans = 0;

  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (grid[i][j] == 1 && visited[i][j] == false) {
        ans = max(ans, maxAreaOfIslandHelper(grid, visited, i, j));
      }
    }
  }

  return ans;
}