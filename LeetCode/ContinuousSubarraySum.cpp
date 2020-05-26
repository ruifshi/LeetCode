#include "stdafx.h"
#include "ContinuousSubarraySum.h"

#include <unordered_map>

bool Solution::checkSubarraySum(vector<int>& nums, int k) {
	int sum = 0;
	unordered_map<int, int> table;

	table[0] = -1; // for [0,0], 0 case

	// prefix sums in a hashmap
	// if sum % k exists, then that means 
	// a previous array sum exists since sum = sum[j] - sum[i] + nums[i]
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];

		if (k != 0) sum = sum % k;

		if (table.find(sum) != table.end()) {
			if (i - table[sum] > 1) return true;
		}
		else {
			table[sum] = i;
		}
	}

	return false;
}

//O(n^2)
/*
int[] sum = new int[nums.length];
sum[0] = nums[0];
for (int i = 1; i < nums.length; i++)
	sum[i] = sum[i - 1] + nums[i];
	for (int start = 0; start < nums.length - 1; start++) {
		for (int end = start + 1; end < nums.length; end++) {
			int summ = sum[end] - sum[start] + nums[start];
			if (summ == k || (k != 0 && summ % k == 0))
				return true;
		}
	}
return false;
}
*/