#include "stdafx.h"
#include "AndroidUnlockPatterns.h"

int Solution::numberOfPatterns(int m, int n) {
	vector<bool> visited(10, false);
	vector<vector<int>> skiptable(10, vector<int>(10, 0));

	skiptable[1][3] = skiptable[3][1] = 2;
    skiptable[1][7] = skiptable[7][1] = 4;
    skiptable[3][9] = skiptable[9][3] = 6;
    skiptable[7][9] = skiptable[9][7] = 8;
    skiptable[1][9] = skiptable[9][1] = skiptable[2][8] = skiptable[8][2] = skiptable[3][7] = skiptable[7][3] = skiptable[4][6] = skiptable[6][4] = 5;

	int ans = 0;

	for(int i = m; i <= n; i++) {
		ans += helper(visited, skiptable, 1, i-1)*4;
		ans += helper(visited, skiptable, 2, i-1)*4;
		ans += helper(visited, skiptable, 5, i-1);
	}

	return ans;
}

int Solution::helper(vector<bool> visited, vector<vector<int>> skiptable, int curr, int remain) {
	if(remain == 0) {
		return 1;
	}

	visited[curr] = true;
	int count = 0;

	for(int i = 1; i <= 9; i++) {
		if(!visited[i] && (skiptable[curr][i] == 0 || visited[skiptable[curr][i]])) {
			count += helper(visited, skiptable, i, remain-1);
		}
	}

	visited[curr] = false;

	return count;
}