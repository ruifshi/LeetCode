#include "stdafx.h"
#include "IntersectionOfTwoArrays.h"

#include <unordered_set>

// O(n)
vector<int> Solution::intersection(vector<int>& nums1, vector<int>& nums2) {
	vector<int> output;
	unordered_set<int> s1(nums1.begin(), nums1.end());
	unordered_set<int> s2(nums2.begin(), nums2.end());

	for (auto a : s1) {
		if (s2.find(a) != s2.end()) output.push_back(a);
	}

	return output;
}