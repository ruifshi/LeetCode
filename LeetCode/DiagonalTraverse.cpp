#include "stdafx.h"
#include "DiagonalTraverse.h"

// O(row*col)
vector<int> Solution::findDiagonalOrder(vector<vector<int>>& matrix) {
	vector<int> ans;
	int rowCnt = matrix.size();

	if(rowCnt < 1) {
		return ans;
	}

	int colCnt = matrix[0].size();

	if(colCnt < 1) {
		return ans;
	}

	bool isUp = true; // f = up to down, t = down to up
	int i = 0, j = 0;

	for(int k = 0; k < rowCnt * colCnt ;) {
		if(!isUp) {
			for(; i < rowCnt && j >= 0; i++, j--) {
				ans.push_back(matrix[i][j]);
				k++;
			}

			if(j < 0 && i < rowCnt) {
				j = 0;
			}

			if(i == rowCnt) {
				j += 2;
				i = rowCnt - 1;
			}

			isUp = true;
		}
		else {
			for(; i >= 0 && j < colCnt; i--, j++) {
				ans.push_back(matrix[i][j]);
				k++;
			}

			if(i < 0 && j < colCnt) {
				i = 0;
			}

			if(j == colCnt) {
				i += 2;
				j = colCnt - 1;
			}

			isUp = false;
		}
	}

	return ans;
}