#include "stdafx.h"
#include "ProductOfArrayExceptSelf.h"

vector<int> Solution::productExceptSelf(vector<int>& nums) {
	vector<int> ans(nums.size(), 0);

	ans[0] = 1;

	//keep track of running produect left of current
	//not including current
	for (int i = 1; i < nums.size(); i++) {
		ans[i] = nums[i - 1] * ans[i - 1];
	}

	//now multiply by the right side values
	int product = 1;
	for (int i = nums.size() - 1; i >= 0; i--) {
		ans[i] = ans[i] * product;
		product *= nums[i];
	}

	return ans;
}