#include "stdafx.h"
#include "HouseRobberII.h"

#include <algorithm>

// O(n)
int Solution::rob(vector<int>& nums) {
	if (nums.empty()) {
		return 0;
	}

	if (nums.size() == 1) {
		return nums[0];
	}

	vector<int> table(nums.size(), 0);
	vector<int> table2(nums.size(), 0);

	table[0] = nums[0];
	table[1] = max(nums[1], table[0]);

	for (int i = 2; i < nums.size() - 1; i++) {	//choose first house and not last
		table[i] = max(table[i - 1], table[i - 2] + nums[i]);
	}

	table2[1] = nums[1];
	table2[2] = max(nums[2], table2[1]);

	for (int i = 3; i < nums.size(); i++) { //don't choose first house and choose last
		table2[i] = max(table2[i - 1], table2[i - 2] + nums[i]);
	}

	return max(table[nums.size() - 2], table2[nums.size() - 1]);
}