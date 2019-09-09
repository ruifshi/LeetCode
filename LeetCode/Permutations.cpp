#include "stdafx.h"
#include "Permutations.h"

vector<vector<int>> ans;

// use backtrack - pick/unpick and find end condition
void permuteHelper(vector<int> nums, int size, vector<int> curr) {
	if (curr.size() == size) {
		ans.push_back(curr);
	}

	for (int i = 0; i < nums.size(); i++) {
		curr.push_back(nums[i]);
		int x = nums[i];
		nums.erase(nums.begin() + i);
		permuteHelper(nums, size, curr);
		nums.insert(nums.begin() + i, x);
		curr.pop_back();
	}

	return;
}

vector<vector<int>> Solution::permute(vector<int>& nums) {
	vector<int> curr;
	permuteHelper(nums, nums.size(), curr);

	return ans;
}