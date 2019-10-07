#include "stdafx.h"
#include "SnakesAndLadders.h"

#include <queue>

//https://www.youtube.com/watch?v=OutDY_ICb80
int Solution::snakesAndLadders(vector<vector<int>>& board) {
	//BFS
	//use a variable step to calculate how many steps
	//for each iteration, find out if the next step can reach to the end
	//if can not reach to the end, then add i= 1~6 to current pos
	if (board.empty()) return 0;
	int step = 0;
	int n = board.size();
	queue<int> q;
	vector<bool> visited(n*n + 1, false);
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		step++;
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int pos = q.front(); 
			q.pop();
			for (int i = 1; i <= 6; i++) {
				int next = pos + i;
				if (next == n * n)
					return step;

				if (visited[next])
					continue;

				visited[next] = true;

				int nextRow = n - 1 - (next - 1) / n;
				int nextCol = (((next - 1) / n) % 2 == 0) ? ((next - 1) % n) : (n - 1 - (next - 1) % n);	//mod 2 to account for zig zap

				//ladder/snake
				if (board[nextRow][nextCol] != -1) {
					next = board[nextRow][nextCol];
					if (next == n * n)
						return step;
				}

				q.push(next);
			}
		}
	}
	return -1;
}

