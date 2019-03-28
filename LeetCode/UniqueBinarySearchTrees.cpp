#include "stdafx.h"
#include "UniqueBinarySearchTrees.h"

#include <vector>

using namespace std;

// https://www.youtube.com/watch?v=YDf982Lb84o
int Solution::numTrees(int n) {
	vector<int> dp(n + 1, 0);

	dp[0] = 1; // 1 way to make unique BST with NULL
	dp[1] = 1; // 1 way to make unique BST with 1 node

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] += dp[j] * dp[i - j - 1];	// Catalan number
		}
	}

	return dp[n];
}