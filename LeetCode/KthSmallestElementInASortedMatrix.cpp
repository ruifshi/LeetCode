#include "stdafx.h"
#include "KthSmallestElementInASortedMatrix.h"

#include <queue>
#include <algorithm>

struct mycomp {
  bool operator()(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) {
    return a.first > b.first;
  }
};

// O(K log min(matrix.size(), k)
int Solution::kthSmallest(vector<vector<int>>& matrix, int k) {
  if (matrix.size() == 0) return 0;
  if (k == 1) return matrix[0][0];

  // value to indices
  // always hold the smallest elements in the front
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int,int>>>, mycomp> q;

  // matrix is row and column sorted so take the first row values
  // and then we'll iterate along the columns
  for (int i = 0; i < min((int)matrix.size(), k); i++) {
    q.push({ matrix[i][0], { i, 0 } });
  }

  // in k iterations, we will have the kth number since q has smallest
  // numbers in the front
  int val = 0;
  while (k-- > 0) {
    val = q.top().first;
    int row = q.top().second.first;
    int col = q.top().second.second;
    q.pop();

    if (col < matrix[0].size() - 1) {
      q.push({ matrix[row][col + 1], {row, col + 1} });
    }
  }

  return val;
}