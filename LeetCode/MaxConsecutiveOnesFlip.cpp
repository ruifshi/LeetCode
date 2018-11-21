#include "stdafx.h"
#include "MaxConsecutiveOnesFlip.h"

int Solution::findMaxConsecutiveOnesFlip(vector<int>& nums) {
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