#include "stdafx.h"
#include "FindKthSmallestPairDistance.h"

#include <algorithm>

// O(NlogN sorting + binary search)
int Solution::smallestDistancePair(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end());

	// find min and max differences in the array
	int min = nums[1] - nums[0], max = nums[nums.size()-1] - nums[0];

	for(int i = 1; i <= nums.size()-2; i++) {
		min = min < nums[i+1] - nums[i] ? min : nums[i+1] - nums[i];
	}

	// do binary search
	while(min < max) {
		int mid = (min + max)/2;
		int count = 0;

		// find the number of elements that differ from the mid
		for(int i = 0, j = 0; i < nums.size(); i++) {
			while(j < nums.size() && nums[j]-nums[i] <= mid) {
				j++;
			}
			count += j-i-1;
		}

		if(count < k) {
			min = mid + 1;
		}
		else {
			max = mid;
		}
	}

	return min;
}