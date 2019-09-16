#include "stdafx.h"
#include "KClosestPointsToOrigin.h"

#include <algorithm>

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