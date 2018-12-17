#include "stdafx.h"
#include "RemoveDuplicatesFromSortedArray.h"

// O(n)
int Solution::removeDuplicates(vector<int>& nums) {
	if(nums.size() == 0) {
		return 0;
	}

	int i = 0;

	// increment count of non same integers i.
    // keep bubling the non same integers to the front
	for(int j = 1; j < nums.size(); j++) {
		if(nums[j] != nums[i]) {
			i++;
			nums[i]=nums[j];
		}
	}

	return i + 1;
}