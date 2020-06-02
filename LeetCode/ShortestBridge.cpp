#include "stdafx.h"
#include "ShortestBridge.h"

#include <queue>

// use DFS to find one island
void dfs(vector<vector<int>>& A, int i, int j, queue<pair<int, int>>&qt) {
  if (i < 0 || j < 0 || i >= A.size() || j >= A[i].size() || A[i][j] != 1)
    return;
  qt.push({ i,j });
  A[i][j] = 2;
  dfs(A, i + 1, j, qt);
  dfs(A, i - 1, j, qt);
  dfs(A, i, j + 1, qt);
  dfs(A, i, j - 1, qt);
}

int Solution::shortestBridge(vector<vector<int>>& A) {
  queue<pair<int, int>>qt;
  int minval = INT_MAX;
  bool found = false;
  for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < A[i].size(); j++) {
      if (A[i][j] == 1) {
        dfs(A, i, j, qt);
        found = true;
        break;
      }
    }
    if (found)
      break;
  }

  // use BFS to expand in all directions from
  // each '1' and maintain the minimum distance.
  // Eventually, you won't find anymore '0's
  int initial = 0;
  while (!qt.empty()) {
    initial++;
    int size = qt.size();
    for (int i = 0; i < size; i++) {
      int r = qt.front().first;
      int c = qt.front().second;
      qt.pop();
      if (r + 1 < A.size()) {
        if (A[r + 1][c] == 0) {
          A[r + 1][c] = initial + 1;
          qt.push({ r + 1,c });
        }
        else if (A[r + 1][c] == 1) {
          minval = min(initial, minval);
        }
      }
      if (c + 1 < A[r].size()) {
        if (A[r][c + 1] == 0) {
          A[r][c + 1] = initial + 1;
          qt.push({ r,c + 1 });
        }
        else if (A[r][c + 1] == 1) {
          minval = min(initial, minval);
        }
      }
      if (r - 1 >= 0) {
        if (A[r - 1][c] == 0) {
          A[r - 1][c] = initial + 1;
          qt.push({ r - 1,c });
        }
        else if (A[r - 1][c] == 1) {
          minval = min(initial, minval);
        }
      }
      if (c - 1 >= 0) {
        if (A[r][c - 1] == 0) {
          A[r][c - 1] = initial + 1;
          qt.push({ r,c - 1 });
        }
        else if (A[r][c - 1] == 1) {
          minval = min(initial, minval);
        }
      }
    }
  }
  return minval - 1;
}