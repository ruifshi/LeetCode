#include "stdafx.h"
#include "TwoSumLessThanK.h"

#include <algorithm>

int Solution::twoSumLessThanK(vector<int>& A, int K) {
	int S = -1;

	sort(A.begin(), A.end());

	for (int i = 0, j = A.size() - 1; i < j; ) {
		if (A[i] + A[j] < K) S = max(S, A[i++] + A[j]);
		else j--;
	}

	return S;
}