#include "stdafx.h"
#include "CombinationSumII.h"

#include <algorithm>

void combinationSum2Helper(vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> &combination, int pos) {
  if (target < 0) return;

  if (!target) {
    res.push_back(combination);
    return;
  }

  for (int i = pos; i < candidates.size(); i++) {
    if (i && candidates[i] == candidates[i - 1] && i != pos) continue; // check duplicate combination and only take first instance of same number

    combination.push_back(candidates[i]);
    combinationSum2Helper(candidates, target - candidates[i], res, combination, i + 1);
    combination.pop_back();
  }
}

vector<vector<int>> Solution::combinationSum2(vector<int>& candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector<vector<int>> res;
  vector<int> combination;
  combinationSum2Helper(candidates, target, res, combination, 0);
  return res;
}