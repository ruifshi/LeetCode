#include "stdafx.h"
#include "IntersectionOfTwoArrays.h"

#include <unordered_map>

// O(n)
vector<int> Solution::intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_map<int, int> table;
	vector<int> output;

	// store all unique elements and assign a tracker of 1
	for (int i = 0; i < nums1.size(); i++)
	{
		if (table.find(nums1[i]) == table.end()) {
			table.insert(pair<int, int>(nums1[i], 1));
		}
		else {
			table[nums1[i]] = 1;
		}
	}

	// If a common element is found, increment the tracker
	for (int i = 0; i < nums2.size(); i++) {
		if (table.find(nums2[i]) != table.end()) {
			table[nums2[i]]++;
		}
	}

	// output all the comment elements
	for (auto x : table) {
		if (x.second > 1) {
			output.push_back(x.first);
		}
	}

	return output;
}