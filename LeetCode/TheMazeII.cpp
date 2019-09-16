#include "stdafx.h"
#include "TheMazeII.h"

#include <queue>

int Solution::shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
	vector<vector<int>> distance(maze.size(), vector<int>(maze[0].size(), INT_MAX));

	distance[start[0]][start[1]] = 0;
	vector<vector<int>> dirs = { {0,1}, {0,-1}, {-1,0}, {1,0} };
	queue<vector<int>> queue;
	queue.push(start);
	while (!queue.empty()) {
		vector<int> s = queue.front();
		queue.pop();
		for (auto dir : dirs) {
			int x = s[0] + dir[0];
			int y = s[1] + dir[1];
			int count = 0;
			while (x >= 0 && y >= 0 && x < maze.size() && y < maze[0].size() && maze[x][y] == 0) {
				x += dir[0];
				y += dir[1];
				count++;
			}
			if (distance[s[0]][s[1]] + count < distance[x - dir[0]][y - dir[1]]) {
				distance[x - dir[0]][y - dir[1]] = distance[s[0]][s[1]] + count;
				queue.push({x - dir[0], y - dir[1]});
			}
		}
	}
	return distance[destination[0]][destination[1]] == INT_MAX ? -1 : distance[destination[0]][destination[1]];
}


/* DFS
int Solution::shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
	vector<vector<int>> distance(maze.size(), vector<int>(maze[0].size(), INT_MAX));
	distance[start[0]][start[1]] = 0;
	dfs(maze, start, distance);
	return distance[destination[0]][destination[1]] == INT_MAX ? -1 : distance[destination[0]][destination[1]];
}

void Solution::dfs(vector<vector<int>>& maze, vector<int> start, vector<vector<int>>& distance) {
	vector<vector<int>> dirs = { {0,1}, {0,-1}, {-1,0}, {1,0} };
	for (auto dir : dirs) {
		int x = start[0] + dir[0];
		int y = start[1] + dir[1];
		int count = 0;

		while (x >= 0 && y >= 0 && x < maze.size() && y < maze[0].size() && maze[x][y] == 0) {
			x += dir[0];
			y += dir[1];
			count++;
		}

		if (distance[start[0]][start[1]] + count < distance[x - dir[0]][y - dir[1]]) { // - dir since while loop adds another to reach out of bounds for condition
			distance[x - dir[0]][y - dir[1]] = distance[start[0]][start[1]] + count;
			dfs(maze, {x - dir[0], y - dir[1]}, distance);
		}
	}

	return;
}
*/