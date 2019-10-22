#include "stdafx.h"
#include "ShortestPathInBinaryMatrix.h"

#include <queue>

int Solution::shortestPathBinaryMatrix(vector<vector<int>>& grid) {
	int steps = 0;
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	while (!q.empty()) {
		++steps;
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			auto c = q.front();
			q.pop();
			if (c.first >= 0 && c.second >= 0 && c.first < grid.size() && c.second < grid.size() && !grid[c.first][c.second]) {
				grid[c.first][c.second] = 1;
				if (c.first == grid.size() - 1 && c.second == grid.size() - 1) return steps;
				for (auto i = -1; i < 2; ++i)
					for (auto j = -1; j < 2; ++j)
						if (i != 0 || j != 0) q.push({ c.first + i, c.second + j });
			}
		}
	}
	return -1;
}