#include "stdafx.h"
#include "UniquePathsIII.h"

/*
The idea is as follows: let's call a "complete path" a path where all 0's are used. 
The number of complete paths at index (x, y) is equal to the sum of complete paths moving up, 
down, left and right. We increment the number of zeros encountered each time we go deeper 
in the recursion tree. If we ever reach the destination cell with the required amont of zeros, 
then we have encountered a complete path and return 1.

O(4^N)
*/
int Solution::uniquePathsIII(vector<vector<int>>& grid) {
	int zeros = 1;
	int x_start, y_start, x_end, y_end;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == 0) zeros++;
			else if (grid[i][j] == 1) {
				x_start = i;
				y_start = j;
			}
			else if (grid[i][j] == 2) {
				x_end = i;
				y_end = j;
			}
		}
	}

	return paths(grid, x_start, y_start, x_end, y_end, 0, zeros);
}

int Solution::paths(vector<vector<int>> &grid,
	int x, int y, int x_end, int y_end, int covered, int required) {
	if (x == x_end && y == y_end && covered == required) {
		return 1;
	}

	grid[x][y] = -1;
	int res = 0;
	vector<vector<int>> dirs = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
	for (auto &dir : dirs) {
		int new_x = x + dir[0];
		int new_y = y + dir[1];
		if (new_x >= 0 && new_y >=0 && new_x < grid.size() && new_y < grid[x].size()
			&& (grid[new_x][new_y] == 0 || grid[new_x][new_y] == 2)) {
			res += paths(grid, new_x, new_y, x_end, y_end, covered + 1, required);
		}
	}
	grid[x][y] = 0;

	return res;
}