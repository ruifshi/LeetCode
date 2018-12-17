#include "stdafx.h"
#include "TrappingRainWater.h"

#include <algorithm>

// O(n)
int Solution::trap(vector<int>& height) {
	if(height.empty() || height.size() == 1) {
		return 0;
	}

	vector<int> left(height.size());
	vector<int> right(height.size());
	int rainWater = 0;

	// keep track of highest building left of current if not current
	left[0] = height[0];
	for(int i = 1; i < height.size(); i++) {
		left[i] = max(left[i-1], height[i]);
	}

	// keep track of highest building right of current if not current
	right[height.size()-1] = height[height.size()-1];
	for(int i = height.size()-2; i >= 0; i--) {
		right[i] = max(right[i+1], height[i]);
	}

	// formula for finding rainwater
	for(int i = 0; i < height.size(); i++) {
		rainWater += min(left[i], right[i]) - height[i];
	}

	return rainWater;
}