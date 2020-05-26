#include "stdafx.h"
#include "SparseMatrixMultiplication.h"

#include <unordered_map>

vector<vector<int>> Solution::multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
	vector<vector<int>> out(A.size(), vector<int>(B[0].size(), 0));
	unordered_map<int, vector<int>> BNonZeroIndexes;

	for (int i = 0; i < B.size(); i++) {
		BNonZeroIndexes[i] = {};
		for (int k = 0; k < B[0].size(); k++) {
			if (B[i][k])  BNonZeroIndexes[i].push_back(k);	//store nonzero value indices for each column
		}
	}


	for (int i = 0; i < A.size(); i++) {
		for (int k = 0; k < A[0].size(); k++) {
			if (A[i][k] != 0) {
				for (int j : BNonZeroIndexes[k]) { //In Row K, Iterate only over indexes that has non-zero values.
					out[i][j] += A[i][k] * B[k][j];
				}
			}
		}
	}

	return out;
}