#include "stdafx.h"
#include "MinimumCostToConnectSticks.h"

#include <queue>

// Use greedy and keep adding lowest numbers first
int Solution::connectSticks(vector<int>& sticks) {
	priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());

	int ans = 0;

	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		
		int b = pq.top();
		pq.pop();

		pq.push(a + b);
		ans += a + b;
	}

	return ans;
}