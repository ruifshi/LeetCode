#include "stdafx.h"
#include "NextGreaterElementI.h"

#include <map>

vector<int> Solution::nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
	vector<int> ans(findNums.size(), -1);

	if(findNums.size() < 1 || nums.size() < 1) {
		return ans;
	}

	map<int, int> nums_index;

	for(int i = 0; i < nums.size(); i++) {
		nums_index[nums[i]] = i;
	}


	for(int i = 0; i < findNums.size(); i++) {
		for(int j = nums_index[findNums[i]]; j < nums.size(); j++) {
			if(findNums[i] < nums[j]) {
				ans[i] = nums[j];
				break;
			}
		}
	}

	return ans;
}