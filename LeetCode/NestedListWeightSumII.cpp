#include "stdafx.h"
#include "NestedListWeightSumII.h"

void dfs(const vector<NestedInteger>& nestedList, int depth, vector<int> &levelSums) {
  // need to resize since we don't know the total depth
  if (levelSums.size() < depth + 1) levelSums.resize(depth + 1);
  
  int size = nestedList.size();

  for (int i = 0; i < size; i++) {
    if (nestedList[i].isInteger()) {
      levelSums[depth] += nestedList[i].getInteger();
    }
    else {
       dfs(nestedList[i].getList(), depth + 1, levelSums);
    }
  }
}

int Solution::depthSumInverse(vector<NestedInteger>& nestedList) {
  vector<int> levelSums;

  dfs(nestedList, 0, levelSums);

  //post processing 
  int sum = 0;
  for (int i = levelSums.size() - 1, depth = 1; i >= 0; i--, depth++) {
    sum += levelSums[i] * depth;
  }

  return sum;
}