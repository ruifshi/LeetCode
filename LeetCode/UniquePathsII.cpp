#include "stdafx.h"
#include "UniquePathsII.h"

int Solution::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	if (obstacleGrid.size() == 0) {
		return 0;
	}

	// if start is an obstacle, then there are no paths
	if (obstacleGrid[0][0] == 1) {
		return 0;
	}

	unsigned int row = obstacleGrid.size();
	unsigned int col = obstacleGrid[0].size();
	vector<vector<unsigned int>> ans(row, vector<unsigned int>(col, 0));

	// starting cell has 1 path to reach
	ans[0][0] = 1;

	// fill out the paths for the first column
	for (int i = 1; i < row; i++) {
		if (obstacleGrid[i][0] == 0 && ans[i - 1][0] == 1) {
			ans[i][0] = 1;
		}
		else {
			ans[i][0] = 0;
		}
	}

	// fill out the paths for the first row
	for (int i = 1; i < col; i++) {
		if (obstacleGrid[0][i] == 0 && ans[0][i-1] == 1) {
			ans[0][i] = 1;
		}
		else {
			ans[0][i] = 0;
		}
	}

	// if there is an obstacle, then there are not paths there
	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {
			if (obstacleGrid[i][j] == 0) {
				ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
			}
			else {
				ans[i][j] = 0;
			}
		}
	}

	return ans[row-1][col-1];
}