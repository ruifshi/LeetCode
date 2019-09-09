#include "stdafx.h"
#include "WalkingRobotSimulation.h"

#include <set>
#include <algorithm>

int Solution::robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
	int x = 0, y = 0;
	int dir = 0; // 0 = up, 1 = right, 2 = down, 3 = left
	vector<int> vert = { 1, 0, -1, 0 };
	vector<int> horiz = { 0, 1, 0, -1 };
	set<pair<int, int>> obset;
	int ans = 0;

	for (auto elem : obstacles) {
		obset.insert(make_pair(elem[0], elem[1]));
	}

	for (int i = 0; i < commands.size(); i++) {
		if (commands[i] > 0) {
			for (int j = 0; j < commands[i]; j++) {
				x = x + horiz[dir];
				y = y + vert[dir];
				if (obset.find(make_pair(x, y)) != obset.end()) {
					x = x - horiz[dir];
					y = y - vert[dir];
					break;
				}
			}
		}
		else {
			if (commands[i] == -1) {
				dir = (dir + 1) % 4;
			}
			else if (commands[i] == -2) {

				dir = (dir + 3) % 4;
			}
		}
		ans = max(ans, x*x + y * y);
	}

	return x * x + y * y;
}