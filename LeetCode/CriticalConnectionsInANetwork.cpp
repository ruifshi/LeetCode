#include "stdafx.h"
#include "CriticalConnectionsInANetwork.h"

#include <algorithm>

//https://www.youtube.com/watch?v=2kREIkF9UAs
vector<vector<int>> Solution::criticalConnections(int n, vector<vector<int>>& connections) {
	check.resize(n + 1);
	// construct graph 
	for (auto &edge : connections) {
		graph[edge[0]].push_back(edge[1]);
		graph[edge[1]].push_back(edge[0]);
	}
	for (int i = 0; i < n; i++)
		if (check[i].index == 0) // not visited 
			crithelper(i, -1);
	return ans;
}

void Solution::crithelper(int v, int parent) {
	check[v].index = time_stamp;
	check[v].lowlink = time_stamp;
	time_stamp++;

	for (auto &w : graph[v]) {
		if (w == parent) continue;
		if (check[w].index == 0) { // not visited
			crithelper(w, v);
			// calc The earliest point that can be reached by a non-father node
			check[v].lowlink = min(check[v].lowlink, check[w].lowlink);
			if (check[w].lowlink > check[v].index) // this must be a bridge 
				ans.push_back({ v,w });
		}
		else {
			check[v].lowlink = min(check[v].lowlink, check[w].index);
		}
	}
}