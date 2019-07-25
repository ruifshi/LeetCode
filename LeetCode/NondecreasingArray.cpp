#include "stdafx.h"
#include "NondecreasingArray.h"

#include <algorithm>

bool Solution::checkPossibility(vector<int>& nums) {
	if (nums.size() <= 2)
		return true;

	if (nums.size() == 0 || nums.size() > 10000)
		return false;

	/*
	for (int i = 0; i < nums.size(); i++) {
		vector<int> temp = nums;
		temp.erase(temp.begin() + i);

		if (is_sorted(temp.begin(), temp.end())) {
			return true;
		}
	}

	return false;
	*/

	int indx = -1;

	for (int i = 0; i < nums.size() - 1; i++) {
		if (nums[i] > nums[i + 1]) {
			if (indx != -1) {
				return false;
			}
			indx = i;
		}
	}

	return (indx == -1 || indx == 0 || indx == nums.size()-2 || nums[indx] <= nums[indx+1] || nums[indx] <= nums[indx+2]);
}