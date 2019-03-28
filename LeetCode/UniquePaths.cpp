#include "stdafx.h"
#include "UniquePaths.h"

#include <vector>

using namespace std;

int Solution::uniquePaths(int m, int n) {
	//initialize first row and column to 1 since there is only one
	//path going down and right from 0
	vector<vector<int>> table(m, vector<int>(n, 1));

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			//add paths coming from left and down
			table[i][j] = table[i - 1][j] + table[i][j - 1];
		}
	}

	return table[m - 1][n - 1];
}