#include "stdafx.h"
#include "MakingALargeIsland.h"

#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

/*
perform a DFS on the grid and find the area of each island. 
To differentiate each island we will assign a unique value which is variable k in our case. 
After finding all the islands and their areas, we will push the 0's in the queue. 
From each 0, we will start a bfs of size 1 and check the number of islands present 
in the vicinity of this 0. With each check, we will update our area variable which denotes the max area connected.
*/
void dfs(vector<vector<int>>& grid, int i, int j, unordered_map<int, int> &area_map, int index) {
  if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) {
    return;
  }

  // this is a 1 so increament area
  area_map[index]++;
  //mark as visited
  grid[i][j] = index;

  dfs(grid, i + 1, j, area_map, index);
  dfs(grid, i, j + 1, area_map, index);
  dfs(grid, i - 1, j, area_map, index);
  dfs(grid, i, j - 1, area_map, index);
}

int Solution::largestIsland(vector<vector<int>>& grid) {
  if (grid.size() == 0) return 0;

  // maps island index to area
  unordered_map<int, int> area_map;
  int index = 2;
  int area = 0;

  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      dfs(grid, i, j, area_map, index);
      // save area in case there is only one island
      area = max(area, area_map[index]);
      index++;
    }
  }

  queue<pair<int, int>> q;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (grid[i][j] == 0) {
        q.push({ i,j });
      }
    }
  }

  vector<vector<int>> dirs = { {0,1}, {1,0}, {-1,0}, {0,-1} };

  while (!q.empty()) {
    pair<int, int> coord = q.front();
    q.pop();
    int x = coord.first;
    int y = coord.second;
    int cur_area = 0;
    unordered_set<int> island_index;  //make sure we're connecting different islands

    for (auto dir : dirs) {
      int x2 = x + dir[0];
      int y2 = y + dir[1];

      if (x2 < 0 || x2 >= grid.size() || y < 0 || y >= grid[0].size() || grid[x2][y2] == 0) {
        continue;
      }

      int cur_index = grid[x2][y2];
      if (!island_index.count(cur_index)) {
        island_index.insert(cur_index);
        cur_area += area_map[cur_index];
      }
    }

    area = max(area, cur_area + 1); //add changed 0
  }

  return area;
}

/*brute force n^4
Intuition

For each 0 in the grid, let's temporarily change it to a 1, then count the size of the group from that square.

Algorithm

For each 0, change it to a 1, then do a depth first search to find the size of that component. The answer is the maximum size component found.

Of course, if there is no 0 in the grid, then the answer is the size of the whole grid.
*/