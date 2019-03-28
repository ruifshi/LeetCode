#include "stdafx.h"
#include "ClimbingStairs.h"

#include <vector>

using namespace std;

int Solution::climbStairs(int n) {
	if (n == 1) {
		return 1;
	}

	vector<int> dp(n + 1, 0);

	dp[1] = 1;	// only 1 way to get to first step
	dp[2] = 2;  // 2 ways of getting to 2nd, take 2 1 steps or take 1 2 step

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}