#include "stdafx.h"
#include "SpiralMatrix.h"

using namespace std;

// O(n), n = number of elements
vector<int> Solution::spiralOrder(vector<vector<int>>& matrix) {
	if(matrix.empty()) {
		return vector<int>();
	}

	int row = matrix.size();
	int col = matrix[0].size();
	vector<int> output(row*col);
	int u = 0;
	int d = row - 1;
	int l = 0;
	int r = col - 1;
	int k = 0;

	while(true) {
		//top left to right, then move down
		for(int i = l; i <= r; i++) {
			output[k++] = matrix[u][i];
		}
		if(++u > d) {
			break;
		}

		//right top to bottom, then move left
		for(int i = u; i <= d; i++) {
			output[k++] = matrix[i][r];
		}
		if(--r < l) {
			break;
		}

		//bottom right to left, then move up
		for(int i = r; i >= l; i--) {
			output[k++] = matrix[d][i];
		}
		if(--d < u) {
			break;
		}

		//left bottom to up, then move right
		for(int i = d; i >= u; i--) {
			output[k++] = matrix[i][l];
		}
		if(++l > r) {
			break;
		}
	}

	return output;
}