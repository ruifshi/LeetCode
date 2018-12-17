#include "stdafx.h"
#include "CourseSchedule.h"

// O(V + E)
// need to detect if there is a cycle. If yes, then can't finish
bool Solution::canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector<vector<int>> graph(numCourses);

	// make the graph (adjacency list)
	for(auto e : prerequisites) {
		graph[e.second].push_back(e.first);
	}

	vector<bool> visited(numCourses, false), onstack(numCourses, false);

	for(int i = 0; i < numCourses; i++) {
		if(dfs_is_cycle(graph, i, visited, onstack)) {
			return false;
		}
	}

	return true;
}

// returns true if cycle is found
// use a stack to keep track of visited nodes as well
// we loop through all the nodes in the adjacency list
// if we see a node that's visited and on the stack, then it's a repeat
bool Solution::dfs_is_cycle(vector<vector<int>> graph, int node, vector<bool> visited, vector<bool> onstack) {
	if(visited[node] == false) {
		visited[node] = onstack[node] = true;

		for(auto v : graph[node]) {
			if(!visited[v] && dfs_is_cycle(graph, v, visited, onstack)) {
				return true;
			}
			else if(onstack[v]) {
				return true;
			}
		}
	}

	onstack[node] = false;
	return false;
}