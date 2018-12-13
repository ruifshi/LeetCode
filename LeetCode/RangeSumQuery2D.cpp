#include "stdafx.h"
#include "RangeSumQuery2D.h"

//https://www.youtube.com/watch?v=PwDqpOMwg6U
NumMatrix::NumMatrix(vector<vector<int>> matrix) {
	if (matrix.size() == 0 || matrix[0].size() == 0) {
		return;
	}

	grid = matrix;
	table.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));

	for (int i = 1; i < table.size(); i++) {
		for (int j = 1; j < table[0].size(); j++) {
			table[i][j] = table[i - 1][j] + table[i][j - 1] + matrix[i - 1][j - 1] - table[i - 1][j - 1];
		}
	}

	return;
}

void NumMatrix::update(int row, int col, int val) {
	grid[row][col] = val;

	for (int i = row + 1; i < table.size(); i++) {
		for (int j = col + 1; j < table[0].size(); j++) {
			table[i][j] = table[i - 1][j] + table[i][j - 1] + grid[i - 1][j - 1] - table[i - 1][j - 1];
		}
	}

	return;
}

int NumMatrix::sumRegion(int row1, int col1, int row2, int col2) {
	return table[row2 + 1][col2 + 1] - table[row1][col2 + 1] - table[row2 + 1][col1] + table[row1][col1];
}

/* Faster alternate solution
class NumMatrix {
public:
	vector<vector<int>> board;

	NumMatrix(vector<vector<int>> matrix) {
		board = matrix;
		int m = board.size(), n = m ? board[0].size() : 0;
		for (int i = 0; i < m; i++)
			for (int j = 1; j < n; j++)
				board[i][j] += board[i][j - 1];
	}

	void update(int row, int col, int val) {
		int cpt = val - board[row][col] + (col > 0 ? board[row][col - 1] : 0);
		for (int i = col; i < board[0].size(); i++)
			board[row][i] += cpt;
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int res = 0;
		for (int i = row1; i <= row2; i++)
			res += board[i][col2] - (col1 > 0 ? board[i][col1 - 1] : 0);
		return res;
	}
};
*/