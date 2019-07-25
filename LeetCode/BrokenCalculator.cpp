#include "stdafx.h"
#include "BrokenCalculator.h"

// While Y is larger than X, add 1 if it is odd, else divide by 2. After, we need to do X - Y additions to reach X
int Solution::brokenCalc(int X, int Y) {
	int ans = 0;

	while (Y > X) {
		ans++;
		if (Y % 2 == 1) {
			Y++;
		}
		else {
			Y /= 2;
		}
	}

	return ans + X - Y;
}