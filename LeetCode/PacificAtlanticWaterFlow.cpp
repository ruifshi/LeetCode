#include "stdafx.h"
#include "PacificAtlanticWaterFlow.h"

vector<pair<int, int>> Solution::pacificAtlantic(vector<vector<int>>& matrix) {
	vector<pair<int, int>> ans;

	if(matrix.size() == 0 || matrix[0].size() == 0) {
		return ans;
	}

	int row = matrix.size();
	int col = matrix[0].size();

	vector<vector<bool>> pacific(row, vector<bool>(col, false));
	vector<vector<bool>> atlantic(row, vector<bool>(col, false));

	for(int i = 0; i < row; i++) {
		helper(matrix, pacific, 0, i, 0);
		helper(matrix, atlantic, 0, i, col-1);
	}

	for(int i = 0; i < col; i++) {
		helper(matrix, pacific, 0, 0, i);
		helper(matrix, atlantic, 0, row-1, i);
	}

	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			if(pacific[i][j] == true && atlantic[i][j] == true) {
				ans.push_back(pair<int, int>(i, j));
			}
		}
	}

	return ans;
}

void Solution::helper(vector<vector<int>>& matrix, vector<vector<bool>>& ocean, int previous, int row, int col) {
	if(row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size() || matrix[row][col] < previous || ocean[row][col]) {
		return;
	}
	
    ocean[row][col] = true;
	previous = matrix[row][col];

	helper(matrix, ocean, previous, row + 1, col);
	helper(matrix, ocean, previous, row - 1, col);
	helper(matrix, ocean, previous, row, col + 1);
	helper(matrix, ocean, previous, row, col - 1);

	return;
}