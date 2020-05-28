#include "stdafx.h"
#include "FirstBadVersion.h"

bool isBadVersion(int n) {
	return true;
}

int Solution::firstBadVersion(int n) {
	int left = 1, right = n;

	while (left < right) {
		int mid = left + (right - left) / 2;

		//always a bad version so there may
		//still be a lower version that's bad
		if (isBadVersion(mid)) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return left;
}