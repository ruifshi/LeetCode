#include "stdafx.h"
#include "WallsAndGates.h"

#include <queue>

void wallsAndGatesHelper(vector<vector<int>> &rooms, int row, int col) {
  queue<pair<int, int>> q;
  q.push({ row, col });

  vector<vector<int>> coords = { {0,1}, {1,0}, {0,-1}, {-1,0} };

  while (!q.empty()) {
    int row1 = q.front().first;
    int col1 = q.front().second;
    q.pop();

    for (auto x : coords) {
      int r = row1 + x[0];
      int c = col1 + x[1];

      if (r < 0 || c < 0 || r >= rooms.size() || c >= rooms[0].size() || rooms[r][c] == -1 || rooms[r][c] <= rooms[row1][col1]) {
        continue;
      }
      rooms[r][c] = rooms[row1][col1] + 1;
      q.push({ r,c });
    }
  }

  return;
}

void Solution::wallsAndGates(vector<vector<int>>& rooms) {
  if (rooms.size() == 0) return;

  for (int i = 0; i < rooms.size(); i++) {
    for (int j = 0; j < rooms[0].size(); j++) {
      if (rooms[i][j] == 0) {
        wallsAndGatesHelper(rooms, i, j);
      }
    }
  }

  return;
}