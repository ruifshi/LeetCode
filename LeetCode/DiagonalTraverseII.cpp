#include "stdafx.h"
#include "DiagonalTraverseII.h"

#include <unordered_map>
#include <algorithm>

vector<int> Solution::findDiagonalOrder2(vector<vector<int>>& nums) {
  //same row + col index means they belong to the same diagonal
  unordered_map<int, vector<int>> mp;
  int key = 0; // keeps track of max size of map for interation

  // The values from the bottom rows are the starting values of the diagonals.
  for (int i = nums.size() - 1; i >= 0; i--) {
    for (int j = 0; j < nums[i].size(); j++) {
      mp[i + j].push_back(nums[i][j]);
      key = max(key, i + j);
    }
  }

  vector<int> out;
  for (int i = 0; i <= key; i++) {
    for (auto &e : mp[i]) out.push_back(e);
  }

  return out;
}