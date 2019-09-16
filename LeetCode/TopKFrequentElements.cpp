#include "stdafx.h"
#include "TopKFrequentElements.h"

#include <unordered_map>
#include <queue>

vector<int> Solution::topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> table;
	priority_queue<pair<int, int>, vector<pair<int, int>>, std::less<pair<int,int>>> q;	//lower values first
	vector<int> ans;

	for (int i = 0; i < nums.size(); i++) {
		if (table.find(nums[i]) == table.end()) {
			table[nums[i]] = 1;
		}
		else {
			table[nums[i]]++;
		}
	}

	for (auto x : table) {
		q.push(make_pair(x.second, x.first));
	}

	for (int i = 0; i < k; i++) {
		int key = q.top().second;
		q.pop();
		ans.push_back(key);
	}

	return ans;
}