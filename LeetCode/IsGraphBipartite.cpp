#include "stdafx.h"
#include "IsGraphBipartite.h"

#include <queue>

bool Solution::isBipartite(vector<vector<int>>& graph) {
	int n = graph.size();

	// color values: 
	// 0 (un-colored), 1 (A set), -1 (B set)
	vector<int> color(n, 0);

	for (int i = 0; i < n; ++i)
	{
		if (color[i] != 0) continue;

		// BFS to color neighbors in opposite colors
		queue<int> q;
		q.push(i);
		color[i] = 1;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int j : graph[cur]) {
				if (color[j] == 0) {
					color[j] = -color[cur]; // use opposite color
					q.push(j);
				}
				else if (color[j] == color[cur])
					return false; // same color used in neighbors
			}
		}
	}
	return true;
}

/*
class Solution {
public:
	bool isBipartite(vector<vector<int>>& graph)
	{
		vector<int> colors(graph.size(), 0); // two groups are 1 and -1 (0 - unassigned)
		for (int i = 0; i < graph.size(); ++i)
			if (colors[i] == 0 && !assign_color(graph, i, 1, colors))
				return false;
		return true;
	}

protected:
	bool assign_color(vector<vector<int>>& graph, int i, int curr_color, vector<int>& colors)
	{
		if (colors[i] == -curr_color) return false; // cannot assign
		if (colors[i] == curr_color) return true; // already correctly assigned
		colors[i] = curr_color;
		for (int n : graph[i]) // assign all 'children' to the opposite group
			if (!assign_color(graph, n, -curr_color, colors)) return false;
		return true;
	}
};
*/