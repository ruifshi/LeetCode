#include "stdafx.h"
#include "FindKPairsWithSmallestSums.h"
#include "math.h"

#include <queue>
#include <set>

vector<pair<int, int>> Solution::kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	vector<pair<int, int>> ans;

	if(nums1.size() <= 0 || nums2.size() <= 0 || k <= 0) {
		return ans;
	}

	priority_queue<pair<int, pair<int, int>>> q;

	for(int i = 0; i < min((int)nums1.size(), k); i++) {
		for(int j = 0; j < min((int)nums2.size(), k); j++) {
			if(q.size() < k) {
				q.push(pair<int, pair<int, int>>(nums1[i] + nums2[j], pair<int, int>(nums1[i],nums2[j])));
			}
			else if(nums1[i] + nums2[j] < q.top().second.first + q.top().second.second) {
				q.push(pair<int, pair<int, int>>(nums1[i] + nums2[j], pair<int, int>(nums1[i],nums2[j])));
				q.pop();
			}
		}
	}

	while(!q.empty()) {
		int x = q.top().second.first;
		int y = q.top().second.second;
		q.pop();

		ans.push_back(pair<int, int>(x, y));
	}

	return ans;
}