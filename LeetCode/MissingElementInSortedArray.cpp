#include "stdafx.h"
#include "MissingElementInSortedArray.h"

/*
First we guess a result rst = nums[0] + k.
We then check if nums[1] is larger than rst. If so, we know all integers between nums[0]+1 and rst are missing, 
thus we can return rst. Otherwise, nums[1] is not missing, we should update our guess to rst = rst + 1.
Similar logic is applied to nums[2], nums[3], ...
*/
int Solution::missingElement(vector<int>& nums, int k) {
	int rst = nums[0] + k;
	for (int i(1); i < nums.size(); ++i) {
		if (nums[i] > rst) {
			return rst;
		}
		else {
			rst += 1;
		}
	}
	return rst;
}

/*
int missingElement(vector<int>& nums, int k) {
	// number of missing elements between the first and last element
	int missing = nums.back() - nums.front() - nums.size() + 1;
	if (k > missing) {
		// if k is larger than the missing counts, it means the k-th missing 
		// element is larger than the last given number and can be easily calculated
		return nums.back() - missing + k;
	}
	int m = nums.size();
	int lo = 0, hi = m - 1;
	while (lo < hi - 1) {
		int mid = (hi - lo) / 2 + lo;
		// calculate the number of missing elements between low and mid
		missing = nums[mid] - nums[lo] - mid + lo;
		if (missing < k) {
			// the number of missing elements is smaller than k, so the element we want is not
			// between low and mid, we instead search between mid and high, but instead of
			// k-th, it will be (k-missing)-th
			k -= missing;
			lo = mid;
		}
		else {
			// the number of missing elements is larger than k, so the element we want is
			// between low and mid, replace high with mid and continue search
			hi = mid;
		}
	}
	// at this point we are confident that lo == hi-1, this means we have found 
	// two consecutive numbers in the given array and all the elements between them 
	// are missing, so the k-th missing element (k is updated) is just nums[lo]+k
	return nums[lo] + k;
}
*/