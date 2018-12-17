#include "stdafx.h"
#include "AndroidUnlockPatterns.h"

// In each case, we use DFS to count the number of valid paths from the current number (1–9) to the remaining numbers. 
// To optimize, calling DFS less than 9 times, we can use the symmetry of the 3 by 3 matrix. If we start from 1 or 3 or 7 or 9, 
// the valid paths number should be the same. If we start from 2 or 4 or 6 or 8, the valid paths number are also the same. 
// Start from 5 is the third case.
int Solution::numberOfPatterns(int m, int n) {
	vector<bool> visited(10, false);
	vector<vector<int>> skiptable(10, vector<int>(10, 0));

	// One of the invalid case can be: I want to create a pattern using 1 and 3. 
	// First you touch 1, moving your finger to the right to reach 3 — oh no, there is 2 
	// in the middle that we don’t want it in my password! Here are all the invalid patterns:
	skiptable[1][3] = skiptable[3][1] = 2;
    skiptable[1][7] = skiptable[7][1] = 4;
    skiptable[3][9] = skiptable[9][3] = 6;
    skiptable[7][9] = skiptable[9][7] = 8;
    skiptable[1][9] = skiptable[9][1] = skiptable[2][8] = skiptable[8][2] = skiptable[3][7] = skiptable[7][3] = skiptable[4][6] = skiptable[6][4] = 5;

	int ans = 0;

	// Now in DFS, we keep trying to find the next valid key. What is a valid candidate? 
	// We need to make sure if the next key hasn’t been visited, and either it’s adjacent to the current key, 
	// or it’s the key in between (recorded as the unselected number on the path)but has been visited.
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