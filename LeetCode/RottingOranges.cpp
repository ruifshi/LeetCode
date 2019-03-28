#include "stdafx.h"
#include "RottingOranges.h"

#include <queue>

using namespace std;

//O(n), visit each node once
int Solution::orangesRotting(vector<vector<int>>& grid) {
	int fruit_count = 0, minutes = -1;
	queue<vector<int>> q;
	vector<vector<int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

	// find cells with rotten fruits and queue it
	for (int i = 0;i < grid.size();i++) {
		for (int j = 0;j < grid[0].size();j++) {
			if (grid[i][j] > 0) fruit_count++;
			if (grid[i][j] == 2) q.push({ i, j });
		}
	}

	//BFS
	while (!q.empty()) {
		//each iteration of the dequeue is 1 minute
		minutes++;
		int size = q.size();

		//for each rotten fruit, need to check all the adjacent fruits
		//if it's fresh, then need to make it rotten and add it to the queue
		//if it's already rotten, then don't need to count it
		for (int k = 0;k < size;k++) {
			vector<int> cur = q.front();
			fruit_count--;
			q.pop();
			for (int i = 0;i < 4;i++) {
				int x = cur[0] + dir[i][0], y = cur[1] + dir[i][1];
				if (x >= grid.size() || x < 0 || y >= grid[0].size() || y < 0 || grid[x][y] != 1) continue;
				grid[x][y] = 2;
				q.push({ x, y });
			}
		}
	}

	//make sure all the fruits are covered, if not, then return -1
	if (fruit_count == 0) return max(0, minutes);
	return -1;
}