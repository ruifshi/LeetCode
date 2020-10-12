#include "stdafx.h"
#include "PathWithMaximumMinimumValue.h"

#include <queue>
#include <algorithm>

//use a priority queue to choose the next step with the maximum value. Keep track of the mininum value along the path.
int Solution::maximumMinimumPath(vector<vector<int>>& A) {
  vector<vector<int>> dirs = { {0,1},{1,0},{0,-1},{-1,0} };
  priority_queue<pair<int, pair<int, int>>> pq;
  pq.push(make_pair(A[0][0], make_pair(0, 0)));
  int n = A.size(), m = A[0].size(), maxscore = A[0][0];
  A[0][0] = -1; // visited
  while (!pq.empty()) {
    
    int a = pq.top().first;
    int i = pq.top().second.first;
    int j = pq.top().second.second;
    pq.pop();
    maxscore = min(maxscore, a);

    if (i == n - 1 && j == m - 1)
      break;

    for (const auto& dir : dirs) {
      int newi = dir[0] + i;
      int newj = dir[1] + j;

      if (newi >= 0 && newi < n && newj >= 0 && newj < m && A[newi][newj] >= 0) {
        pq.push(make_pair(A[newi][newj], make_pair(newi, newj)));
        A[newi][newj] = -1; // visited
      }
    }
  }

  return maxscore;
}