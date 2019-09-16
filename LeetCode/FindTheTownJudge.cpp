#include "stdafx.h"
#include "FindTheTownJudge.h"

#include <unordered_map>
#include <set>

/* you can build an adjacency matrix and the key is to find a number that is in every list but isn't a key himself
1 - 3, 4
2 - 3, 4
4 - 3
In the end, the judge should have N-1 people trust him

This is a direct graph and you find the vertex that has no outgoing edge
*/
int Solution::findJudge(int N, vector<vector<int>>& trust) {
	unordered_map<int, set<int>> adj;

	if (trust.size() == 0) return 1;
	if (trust.size() == 1) return trust[0][1];

	for (int i = 0; i < trust.size(); i++) {
		adj[trust[i][0]].insert(trust[i][1]);
	}

	int judge = -1;
	for (int i = 1; i <= N; i++) {
		if (adj.find(i) == adj.end()) {
			if (judge != -1) {	//if there are multiple people that don't trust anyone, then there is no single person that is trusted by everyone
				return -1;
			}
			judge = i;
		}
	}

	if (judge == -1) {
		return -1;
	}

	for (auto x : adj) {
		if (x.second.find(judge) == x.second.end()) {
			return -1;
		}
	}

	return judge;
}

/*
	int findJudge(int N, vector<vector<int>>& trust) {
		vector<int> count(N + 1, 0);
		for (auto& t : trust)
			count[t[0]]--, count[t[1]]++;
		for (int i = 1; i <= N; ++i) {
			if (count[i] == N - 1) return i;
		}
		return -1;
	}
*/