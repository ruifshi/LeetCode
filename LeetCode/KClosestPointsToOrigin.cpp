#include "stdafx.h"
#include "KClosestPointsToOrigin.h"

#include <algorithm>

/*
Quick Select
*/
// p1 is smaller dist than p2
bool compare(vector<int> &p1, vector<int> &p2) {
  return (p1[0] * p1[0] + p1[1] * p1[1]) <= (p2[0] * p2[0] + p2[1] * p2[1]);
}

int kClosestHelper(vector<vector<int>>& points, int l, int r) {
  // choose a pivot
  vector<int> pivot = points[l];

  while (l < r) {
    // iterate right until we find element smaller
    while (l < r && compare(pivot, points[r]))
      r--;

    // found a element in right half smaller, move it to left
    points[l] = points[r];

    // iterate left until we find element bigger
    while (l < r && compare(points[l], pivot))
      l++;

    // found element in left half bigger, move to right
    points[r] = points[l];
  }

  // left now points to largest element smaller than pivot
  // add pivot back
  points[l] = pivot;
  return l;
}

vector<vector<int>> Solution::kClosest(vector<vector<int>>& points, int K) {
  int len = points.size(), l = 0, r = len - 1;
  while (l <= r) {
    // binary search until we find pivot that is kth element
    int mid = kClosestHelper(points, l, r);
    if (mid == K) break;
    if (mid < K) {
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }

  return vector<vector<int>>(points.begin(), points.begin() + K);
}

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

/* O(nlogn)
vector<vector<int>> Solution::kClosest(vector<vector<int>>& points, int K) {
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
*/