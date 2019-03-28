#include "stdafx.h"
#include "Triangle.h"

#include <algorithm>

// http://www.zrzahid.com/min-sum-path-in-triangle/
int Solution::minimumTotal(vector<vector<int>>& triangle) {
	if (triangle.size() == 0) {
		return 0;
	}

	int levels = triangle.size();

	vector<vector<int>> dp(levels, vector<int>(levels, 0));

	dp[levels - 1] = triangle[levels-1];

	for (int i = levels - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
		}
	}

	return dp[0][0];
}