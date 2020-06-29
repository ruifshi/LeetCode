#include "stdafx.h"
#include "NumberOfDistinctIslands.h"

#include <set>

void dfs(vector<vector<int>>& grid, int i0, int j0, int i, int j, vector<vector<int>> &island) {
  if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 2)
    return;

  if (grid[i][j] != 2 && grid[i][j] == 1) {
    grid[i][j] = 2;
    island.push_back({ i - i0, j - j0 });
    dfs(grid, i0, j0, i + 1, j, island);
    dfs(grid, i0, j0, i, j + 1, island);
    dfs(grid, i0, j0, i - 1, j, island);
    dfs(grid, i0, j0, i, j - 1, island);
  }
}

int Solution::numDistinctIslands(vector<vector<int>>& grid) {
  if (grid.size() == 0) return 0;
  if (grid[0].size() == 0) return 0;

  // we orient all islands coordinates as if they started at (0,0)
  // this set keep tracks of unique ones
  set<vector<vector<int>>> islands;

  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      // keeps track of coordinates of current island
      vector<vector<int>> island;
      if (grid[i][j] != 2 && grid[i][j] == 1) {
        dfs(grid, i, j, i, j, island);
        islands.insert(island);
      }
    }
  }

  return islands.size();
}