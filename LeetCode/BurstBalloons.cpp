#include "stdafx.h"
#include "BurstBalloons.h"

#include <algorithm>

//If we assume the balloon at index Last to be the last balloon to be burst in this sub-array, we would say the coined gained to be-A[left-1]*A[last]*A[right+1].
//Also, the total Coin Gained would be this value, plus dp[left][last – 1] + dp[last + 1][right], where dp[i][j] means maximum coin gained for sub - array with indices i, j.
//Therefore, for each value of Left and Right, we need find and choose a value of Last with maximum coin gained, and update the dp array.
//Our Answer is the value at dp[1][N].
int Solution::maxCoins(vector<int>& nums) {
	int size = nums.size();

	// add 1's the ends since you may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
	nums.insert(nums.begin(), 1);
	nums.push_back(1);

	vector<vector<int>> dp(size + 2, vector<int>(size + 2, 0));

	for (int length = 1; length <= size; length++) {
		//right most position i + length - 1 = size
		for (int i = 1; i <= size - length + 1; i++) {	// left
			int j = i + length - 1;	// right
			for (int k = i; k <= j; k++) {	// last balloon to be burst
				dp[i][j] = max(dp[i][j], dp[i][k - 1] + nums[i - 1] * nums[k] * nums[j + 1] + dp[k + 1][j]);
			}
		}
	}

	return dp[1][size];
}