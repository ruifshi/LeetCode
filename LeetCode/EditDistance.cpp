#include "stdafx.h"
#include "EditDistance.h"

#include <vector>
#include <algorithm>

//O(word1.size() * word2.size())
int Solution::minDistance(string word1, string word2) {
	int n = word1.size();
	int m = word2.size();

	if (n*m == 0) {
		return n + m;
	}

	vector<vector<int>> table(n+1, vector<int>(m+1, 0));	//+1 for the NULL string

	for (int i = 0; i <= n; i++) {	//compare all the substring to NULL string
		table[i][0] = i;
	}

	for (int j = 0; j <= m; j++) {
		table[0][j] = j;
	}

	// iterate through the rest of the table and look at the operations
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int top = table[i - 1][j] + 1;	//del
			int left = table[i][j - 1] + 1;	//insert
			int diag = table[i - 1][j - 1];	//replace
			if (word1.at(i - 1) != word2.at(j - 1)) {	//if chars are not the same, then increase
				diag += 1;
			}
			table[i][j] = min(top, min(left, diag));
		}
	}

	return table[n][m];
}