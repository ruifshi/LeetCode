#include "stdafx.h"
#include "FindPeakElement.h"

// O(logn)
// In this approach, we make use of the fact that two consecutive numbers nums[j]nums[j] 
// and nums[j + 1]nums[j+1] are never equal. Thus, we can traverse over the numsnums array 
// starting from the beginning. Whenever, we find a number nums[i]nums[i], we only need to 
// check if it is larger than the next number nums[i+1]nums[i+1] for determining if nums[i]nums[i] 
// is the peak element. The reasoning behind this can be understood by taking the following three cases 
// which cover every case into which any problem can be divided.
int Solution::findPeakElement(vector<int>& nums) {
	int l = 0, r = nums.size() - 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (nums[mid] > nums[mid + 1])
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}