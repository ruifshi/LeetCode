#include "stdafx.h"
#include "SubarraySumEqualsK.h"

#include <unordered_map>

// https://www.youtube.com/watch?v=HbbYPQc-Oo4
int Solution::subarraySum(vector<int>& nums, int k) {
	if (nums.size() == 0)
		return 0;

  // sums to number of times seen
	unordered_map<int, int> subarr_sums;

	int sum = 0;
	int count = 0;

	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];

		if (sum == k)	//found subarr 
			count++;

		// prefix sums. k = the sum between intervals so sum - k
		if (subarr_sums.find(sum - k) != subarr_sums.end()) {
			count += subarr_sums[sum - k];
		}

		subarr_sums[sum]++;
	}

	return count;
}

/* O(n^2)
public class Solution {
	public int subarraySum(int[] nums, int k) {
		int count = 0;
		for (int start = 0; start < nums.length; start++) {
			int sum = 0;
			for (int end = start; end < nums.length; end++) {
				sum += nums[end];
				if (sum == k)
					count++;
			}
		}
		return count;
	}
}
*/