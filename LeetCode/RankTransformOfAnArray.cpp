#include "stdafx.h"
#include "RankTransformOfAnArray.h"

#include <unordered_map>
#include <algorithm>

vector<int> Solution::arrayRankTransform(vector<int>& arr) {
  if (arr.size() == 0) return {};

  vector<int> sortedArr(arr);
  sort(sortedArr.begin(), sortedArr.end());

  unordered_map<int, int> rank; // maps val to rank

  for (int i = 0; i < sortedArr.size(); i++) {
    if (rank.find(sortedArr[i]) == rank.end()) {   // for duplicates
      rank[sortedArr[i]] = rank.size() + 1;
    }
  }

  for (int i = 0; i < arr.size(); i++) {
    arr[i] = rank[arr[i]];
  }

  return arr;
}