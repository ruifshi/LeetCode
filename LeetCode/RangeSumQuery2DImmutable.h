#pragma once

#include <vector>

using namespace std;

class NumMatrix2 {
public:
	NumMatrix2(vector<vector<int>>& matrix);

	int sumRegion(int row1, int col1, int row2, int col2);

	vector<vector<int>> table;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */