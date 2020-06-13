#include "stdafx.h"
#include "TwoSums.h"

#include <unordered_map>

vector<int> Solution::twoSum(vector<int>& nums, int target) {
  // maps number to index
	unordered_map<int, int> indices;
	for (int i = 0; i < nums.size(); i++) {
		if (indices.find(target - nums[i]) != indices.end()) {
			return { indices[target - nums[i]], i };
		}
		indices[nums[i]] = i;
	}
	return {};
}