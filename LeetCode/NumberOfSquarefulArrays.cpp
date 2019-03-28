#include "stdafx.h"

#include "NumberOfSquarefulArrays.h"

// Count numbers ocurrence.
// For each number i, find all possible next number j that i + j is square.
// Backtracking using dfs.
int Solution::numSquarefulPerms(vector<int>& A) {
	for (int &a : A) count[a]++;
	for (auto &i : count) {
		for (auto &j : count) {
			int x = i.first, y = j.first, s = sqrt(x + y);
			if (s * s == x + y)
				cand[x].insert(y);
		}
	}
	for (auto e : count)
		dfs(e.first, A.size() - 1);
	return res;
}

void Solution::dfs(int x, int left) {
	count[x]--;
	if (!left) res++;
	for (int y : cand[x])
		if (count[y] > 0)
			dfs(y, left - 1);
	count[x]++;
}