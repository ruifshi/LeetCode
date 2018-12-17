#include "stdafx.h"
#include "MinimumPathSum.h"

#include <algorithm>

// O(row * col)
int Solution::minPathSum(vector<vector<int>>& grid) {
	if (grid.size() == 0 || grid[0].size() == 0) {
		return 0;
	}

	int n = grid.size();
	int m = grid[0].size();

	vector<vector<int>> table(n, vector<int>(m, 0));
	int sum = 0;

	for (int i = 0; i < n; i++) {	//populate values going down
		sum += grid[i][0];
		table[i][0] = sum;
	}

	sum = table[0][0];	//don't re-add the starting value
	for (int j = 1; j < m; j++) {	//populate values going right
		sum += grid[0][j];
		table[0][j] = sum;
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			table[i][j] = min(table[i - 1][j], table[i][j - 1]) + grid[i][j];	//minimum of coming from up or left plus current
		}
	}

	return table[n-1][m-1];
}