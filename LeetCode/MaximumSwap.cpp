#include "stdafx.h"
#include "MaximumSwap.h"

#include <string>

using namespace std;

int Solution::maximumSwap(int num) {
	string numstr = std::to_string(num);

	int maxidx = -1; int maxdigit = -1;
	int leftidx = -1; int rightidx = -1;

	for (int i = numstr.size() - 1; i >= 0; --i) {
		// current digit is the largest by far
		// continue here and keep rightidx separate
		// in case s[0] is the biggest digit
		if (numstr[i] > maxdigit) {
			maxdigit = numstr[i];
			maxidx = i;
			continue;
		}

		// best candidate for max swap if there is no more 
		// such situation on the left side
		if (numstr[i] < maxdigit) {
			leftidx = i;
			rightidx = maxidx;
		}
	}

	// num is already in order
	if (leftidx == -1) return num;

	std::swap(numstr[leftidx], numstr[rightidx]);

	return std::stoi(numstr);
}

/*
class Solution {
		public int maximumSwap(int num) {
				char[] A = Integer.toString(num).toCharArray();
				int[] last = new int[10];
				for (int i = 0; i < A.length; i++) {
						last[A[i] - '0'] = i;
				}

				for (int i = 0; i < A.length; i++) {
						for (int d = 9; d > A[i] - '0'; d--) {
								if (last[d] > i) {
										char tmp = A[i];
										A[i] = A[last[d]];
										A[last[d]] = tmp;
										return Integer.valueOf(new String(A));
								}
						}
				}
				return num;
		}
}
*/