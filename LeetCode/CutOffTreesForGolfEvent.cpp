#include "stdafx.h"
#include "CutOffTreesForGolfEvent.h"

#include <queue>
#include <tuple>

int Solution::cutOffTree(vector<vector<int>>& forest) {
	if (forest.empty() || forest[0].empty()) return 0;
	int m = forest.size(), n = forest[0].size();
	vector<vector<int>> trees;
	// get all the tree positions and sort based on height
	// trees[i][0] is height. The default comparison of vector compare first element before other elements.
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (forest[i][j] > 1) trees.push_back({ forest[i][j], i, j });
		}
	}
	sort(trees.begin(), trees.end());
	int ans = 0;
	int cur_row = 0, cur_col = 0;
	// accumulate all the paths
	for (int i = 0; i < trees.size(); i++) {
		int step = next_step(forest, cur_row, cur_col, trees[i][1], trees[i][2]);
		// if next tree cannot be reached, step = -1;
		if (step == -1) return -1;
		ans += step;
		cur_row = trees[i][1];
		cur_col = trees[i][2];
	}
	return ans;
}

// BFS to find shortest path to next tree; if cannot reach next tree, return -1
int Solution::next_step(vector<vector<int>>& forest, int sr, int sc, int er, int ec) {
	if (sr == er && sc == ec) return 0;
	int m = forest.size(), n = forest[0].size();
	queue<pair<int, int>> myq;
	myq.push({ sr, sc });
	vector<vector<int>> visited(m, vector<int>(n, 0));
	visited[sr][sc] = 1;
	int step = 0;
	vector<int> dir = { -1, 0, 1, 0, -1 };
	while (!myq.empty()) {
		step++;
		int sz = myq.size();
		for (int i = 0; i < sz; i++) {
			int row = myq.front().first, col = myq.front().second;
			myq.pop();
			for (int i = 0; i < 4; i++) {
				int r = row + dir[i], c = col + dir[i + 1];
				if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] == 1 || forest[r][c] == 0) continue;
				if (r == er && c == ec) return step;
				visited[r][c] = 1;
				myq.push({ r, c });
			}
		}
	}
	return -1;
}

/*
int Solution::cutOffTree(vector<vector<int>>& forest) {
	int rows = forest.size();
	int cols = rows ? forest[0].size() : 0;

	if (rows == 0 || cols == 0) {
		return 0;
	}

	// Start location is blocked
	if (forest[0][0] == 0) {
		return -1;
	}

	// Min queue of trees based on height
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> trees;

	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c) {
			if (forest[r][c] > 1) {
				trees.push({ forest[r][c], {r, c} });
			}
		}
	}

	// Legal moves
	vector<pair<int, int>> moves = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

	// Track visited
	vector<vector<int>> visited(rows, vector<int>(cols, -1));

	// Total distance
	int totalDist = 0;

	// Start location
	pair<int, int> start = { 0, 0 };

	// Tree ID
	int i = 0;

	// Iterate through trees in increasing height order
	while (!trees.empty()) {
		pair<int, int> to = trees.top().second;
		trees.pop();

		// Level order traversal
		bool found = false;
		int dist = -1;
		queue<pair<int, int>> qu;

		qu.push({ start.first, start.second });
		visited[start.first][start.second] = i;

		while (!qu.empty() && !found) {
			++dist;

			for (int j = 0, r, c, size = qu.size(); j < size && !found; ++j) {
				tie(r, c) = qu.front();
				qu.pop();

				// Break if target location found
				if (r == to.first && c == to.second) {
					found = true;
					break;
				}

				for (int m = 0, nr, nc; m < 4; ++m) {
					// New location
					nr = r + moves[m].first;
					nc = c + moves[m].second;

					// Skip out of bound, blockages and already scheduled
					if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || visited[nr][nc] == i || forest[nr][nc] == 0) {
						continue;
					}

					// Mark visited asap otherwise it will be scheduled mutiple times
					visited[nr][nc] = i;
					qu.push({ nr, nc });
				}
			}
		}

		// Return if not found
		if (!found) {
			return -1;
		}

		// Update total distance
		totalDist += dist;

		// Update start
		start = to;

		// Update id
		++i;
	}

	return totalDist;
}
*/