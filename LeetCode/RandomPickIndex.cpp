#include "stdafx.h"
#include "RandomPickIndex.h"

Solution2::Solution2(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		table[nums[i]].push_back(i); // save indices of same number
	}
}

int Solution2::pick(int target) {
	return table[target][rand() % table[target].size()];
}