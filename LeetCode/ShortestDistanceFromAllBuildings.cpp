#include "stdafx.h"
#include "ShortestDistanceFromAllBuildings.h"

#include <queue>

// O(m^2 * n^2)
int Solution::shortestDistance(vector<vector<int>>& grid) {
	//Do BFS from all buildings to all squares with 0
	//hit 2D array keeps track of how many times a building has reached that square
	//distSum 2D array keeps track of the distance from building to square
	//search through arrays to find the minimum distance that all buildings hit
	//check if all buildings are connected

	if(grid.size() == 0 || grid[0].size() == 0) {
		return -1;
	}

	int buildings = 0;

	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid[i].size(); j++) {
			if(grid[i][j] == 1) {
				buildings++;
			}
		}
	}

	vector<vector<int>> hits(grid.size(), vector<int>(grid[0].size(), 0));
	vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), 0));

	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid[i].size(); j++) {
			if(grid[i][j] == 1) {
				if(!helper(grid, hits, dist, buildings, i, j))
				{
					return -1;
				}
			}
		}
	}

	int ans = INT_MAX;

	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid[i].size(); j++) {
			if(hits[i][j] == buildings && grid[i][j] == 0) {
				ans = ans < dist[i][j] ? ans : dist[i][j];
			}
		}
	}

	return ans == INT_MAX ? -1 : ans;
}

bool Solution::helper(vector<vector<int>>& grid, vector<vector<int>>& hits, vector<vector<int>>& dist, int buildings, int row, int col) {
	vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
	queue<pair<int, int>> q;
	int buildingsCount = 0;

	q.push(pair<int, int>(row, col));
	visited[row][col] = true;

	while(!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		vector<pair<int, int>> pos = { {i + 1, j}, {i - 1, j}, {i, j + 1}, {i, j - 1} };

		for(auto p : pos) {
			int x = p.first;
			int y = p.second;

			if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && !visited[x][y]) {
				visited[x][y] = true;

				if(grid[x][y] == 1) {
					buildingsCount++;
				}
				else if(grid[x][y] == 0) {
					hits[x][y]++;
					dist[x][y] += abs(row-x) + abs(col-y);
					q.push(pair<int, int>(x, y));
				}
			}
		}
	}

	return buildingsCount == buildings-1;
}