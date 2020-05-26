#include "stdafx.h"
#include "MonotonicArray.h"

bool Solution::isMonotonic(vector<int>& A) {
	bool increasing = true, decreasing = true;

	for (int i = 1; i < A.size(); i++) {
		if (A[i - 1] < A[i]) {
			decreasing = false;
		}

		if (A[i - 1] > A[i]) {
			increasing = false;
		}
	}

	return increasing || decreasing;
}