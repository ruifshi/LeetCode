#include "stdafx.h"
#include "KthLargestElementInAnArray.h"

#include <queue>

// O(nlogn) due to sorting
int Solution::findKthLargest(vector<int>& nums, int k) {
	/*
	priority_queue<int> q;

	for(int i = 0; i < nums.size(); i++) {
		q.push(nums[i]);
	}

	int ans;

	for(int i = 0; i < k; i++) {
		ans = q.top();
		q.pop();
	}

	return ans;
	*/

	sort (nums.begin(), nums.end());
        
    return nums[nums.size()-k];
}