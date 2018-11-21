#include "stdafx.h"
#include "IntersectionOfTwoArrays.h"

#include <unordered_map>

vector<int> Solution::intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_map<int, int> table;
	vector<int> output;

	for(int i = 0; i < nums1.size(); i++)
	{
		if(table.find(nums1[i]) == table.end()) {
			table.insert(pair<int, int>(nums1[i], 0));
		}
		else {
			table[nums1[i]]++;
		}
	}

	for(int i = 0; i < nums2.size(); i++) {
		if(table.find(nums2[i]) != table.end()) {
			table[nums2[i]]++;
		}
	}

	for(auto x: table) {
		if(x.second > 1) {
			output.push_back(x.first);
		}
	}

	return output;
}