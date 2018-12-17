#include "stdafx.h"
#include "FirstMissingPositive.h"

// O(n)
int Solution::firstMissingPositive(vector<int>& nums) {
	if(nums.size() == 0) {
		return 1;
	}

	// remove 0 and negatives from consideration
	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] <= 0) {
			nums[i] = INT_MAX;
		}
	}

	// use the index of the array to keep track of which
	// numbers exist in the array. If the element in the
	// array is negative, then that index as a number exits
	// in the array.
	for(int i = 0; i < nums.size(); i++) {
		int val = abs(nums[i]);
		if(val <= nums.size()) {
			nums[val-1] = -abs(nums[val-1]);	// -1 since index 0 represents number 1
		}
	}

	// The first index with a positive number means that number
	// doesn't exist in the array.
	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] > 0) {
			return i+1;
		}
	}

	return nums.size() + 1;
}