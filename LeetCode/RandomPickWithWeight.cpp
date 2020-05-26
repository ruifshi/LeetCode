#include "stdafx.h"
#include "RandomPickWithWeight.h"

#include <algorithm>

Solution::Solution(vector<int>& w) {
	if (w.size() == 0) return;

	prefixSums.push_back(w[0]);
	for (int i = 1; i < w.size(); i++) {
		prefixSums.push_back(prefixSums.back() + w[i]);
	}
}

int Solution::pickIndex() {
	int target = rand() % prefixSums.back();
	return upper_bound(prefixSums.begin(), prefixSums.end(), target) - prefixSums.begin();
}

/*
int Solution::pickIndex() {
	int target = rand() % prefixSums.back();

	int l = 0, r = prefixSums.size() - 1, mid = 0;

	while (l < r) {
		mid = l + (r - l) / 2;
		if (prefixSums[mid] == target) {
			return mid;
		}
		else if (target < prefixSums[mid]) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	return mid;
}
*/