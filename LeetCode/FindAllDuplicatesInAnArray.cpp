#include "stdafx.h"
#include "FindAllDuplicatesInAnArray.h"

vector<int> findDuplicates(vector<int>& nums) {
  vector<int> ans;

  for (auto num : nums) {
    if (nums[abs(num) - 1] < 0) {  // seen before
      ans.push_back(abs(num));
    }
    nums[abs(num) - 1] *= -1;
  }

  return ans;
}

/*
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;
    unordered_set<int> seen;

    for (auto& num : nums) {
        if (seen.count(num) > 0)
            ans.push_back(num);
        else
            seen.insert(num);
    }

    return ans;
}
*/