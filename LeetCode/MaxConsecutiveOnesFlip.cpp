#include "stdafx.h"
#include "MaxConsecutiveOnesFlip.h"

#include <algorithm>

// O(n)
int Solution::findMaxConsecutiveOnesFlip(vector<int>& nums) {

	// Just keep track of the current and previous number of 1s, and max of their sum. 
	// If there is more than one zero, previous number of 1s will become zero. 
	// In the end, add 1 to the max for the flip, unless the array only has 1st.
    int ones = 0, prev_ones = 0, max_ones = 0, size = nums.size();
    for (int i = 0; i < size; ++i)
    {
        if (nums[i] == 0) {
			max_ones = max_ones > (prev_ones + ones) ? max_ones : (prev_ones + ones);
			prev_ones = ones;
			ones = 0;
		}
        else {
			ones++;
		}
    }
    return max(max_ones, prev_ones + ones) + (ones == size ? 0 : 1);
}