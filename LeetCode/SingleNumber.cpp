#include "stdafx.h"
#include "SingleNumber.h"
#include <set>

int Solution::singleNumber(vector<int>& nums) {
	set<int> table;

	for (int i = 0; i < nums.size(); i++) {
		if (table.find(nums[i]) == table.end()) {
			table.insert(nums[i]);
		}
		else {
			table.erase(nums[i]);
		}
	}

	return *table.begin();
}

/*
	a = 0
	for i in nums:
		a ^= i
	return a
*/