#include "stdafx.h"

int maxSubArray(int* nums, int numsSize) {
  int i;
  int max = 0;
  int sum = 0;

  max = sum = nums[0];

	for(i = 1; i < numsSize; i++) {
		sum = sum + nums[i] > nums[i] ? sum + nums[i] : nums[i];

		if(sum > max) {
			max = sum;
		}
	}

	return max;
}