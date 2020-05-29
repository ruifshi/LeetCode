#include "stdafx.h"
#include "RangeSumQuery2DImmutable.h"

NumMatrix2::NumMatrix2(vector<vector<int>>& matrix) {
	if (matrix.size() == 0 || matrix[0].size() == 0) {
		return;
	}

	table.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));

	// sums of each area from 0,0
	// need -last element beacuse we are adding it 2x in the add
	for (int i = 1; i < table.size(); i++) {
		for (int j = 1; j < table[0].size(); j++) {
			table[i][j] = table[i - 1][j] + table[i][j - 1] + matrix[i - 1][j - 1] - table[i - 1][j - 1];
		}
	}

	return;
}

int NumMatrix2::sumRegion(int row1, int col1, int row2, int col2) {
	// area from 0,0 minus the top side, bottom side and add the area that got subtracted 2x
	return table[row2 + 1][col2 + 1] - table[row1][col2 + 1] - table[row2 + 1][col1] + table[row1][col1];
}