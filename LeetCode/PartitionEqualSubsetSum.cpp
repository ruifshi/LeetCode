#include "stdafx.h"
#include "PartitionEqualSubsetSum.h"

bool backtrack(vector<int>& nums, int start, int target) {
  if (target <= 0) return target == 0;

  // pick the number or not
  for (int i = start; i < nums.size(); i++)
    if (backtrack(nums, i + 1, target - nums[i])) return true;
  return false;
}

bool Solution::canPartition(vector<int>& nums) {
  int sum = 0;
  for (auto &n : nums) sum += n;

  // can only partition if sum is even
  return !(sum & 1) && backtrack(nums, 0, sum/2);
}

/*
class Solution {
private:
    unordered_set<string> visited;
    bool dfs(vector<int>& nums, int idx, int target) {
        if (target<0) return false;
        if (target==0) return true;

        if (visited.count(to_string(idx)+'-'+to_string(target))) return false;

        for (int i=idx; i<nums.size(); i++) {
            if (dfs(nums,i+1,target-nums[i])) return true;
        }

        visited.insert(to_string(idx)+'-'+to_string(target));
        return false;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        return sum%2==0 && dfs(nums,0,sum/2);
    }
};
*/