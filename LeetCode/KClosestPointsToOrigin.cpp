#include "stdafx.h"
#include "KClosestPointsToOrigin.h"

#include <algorithm>

// O(nlogn)
vector<vector<int>>  Solution::kClosest(vector<vector<int>>& points, int K) {
	vector<pair<int, int>> dist;
	vector<vector<int>> ans;

	for (int i = 0; i < points.size(); i++) {
		dist.push_back(make_pair(points[i][0] * points[i][0] + points[i][1] * points[i][1], i));
	}

	sort(dist.begin(), dist.end());

	for (int i = 0; i < K; i++) {
		ans.push_back(points[dist[i].second]);
	}

	return ans;
};

/* O(nlogk)
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		priority_queue<pair<int, int>> q;
		vector<vector<int>> ans;

		for (int i = 0; i < points.size(); i++) {
			q.push(make_pair(points[i][0] * points[i][0] + points[i][1] * points[i][1], i));
	  	if(q.size() > K) {
  		q.pop();
		}
	}


  while(!q.empty()) {
		ans.push_back(points[q.top().second]);
	  q.pop();
  }

	return ans;
}
*/