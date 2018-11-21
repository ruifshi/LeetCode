#include "stdafx.h"
#include "MaxConsecutiveOnes.h"

int Solution::findMaxConsecutiveOnes(vector<int> &nums) {
	int local_max = 0, max = 0;

	for(int i = 0; i < nums.size(); i++) {
		if(nums[i]) {
			local_max++;
		}
		else {
			max = max > local_max ? max : local_max;
			local_max = 0;
		}
	}

	return max > local_max ? max : local_max;
}