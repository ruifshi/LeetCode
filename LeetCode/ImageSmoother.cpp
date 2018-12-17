#include "stdafx.h"
#include "ImageSmoother.h"
#include <algorithm>

// O(row*col)
vector<vector<int>> Solution::imageSmoother(vector<vector<int>>& M) {
	int row = M.size();
	int col = M[0].size();

	// Iterate through each element and apply the rules with respect
	// to the elements around it. Keep the results in some upper bits
	// to save space and at the end, shift the bits out.
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {

			int count = 0;
			int sum = 0;
			for(int k = max(i - 1, 0); k < min(i + 2, row); k++) {
				for(int l = max(j - 1, 0); l < min(j + 2, col); l++) {
					sum += M[k][l] & 0xFF;
					count++;
				}
			}
			
			M[i][j] |= ((sum/count) << 8) & 0xFF00;
		}
	}

	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			M[i][j] >>= 8;
		}
	}

	return M;
}