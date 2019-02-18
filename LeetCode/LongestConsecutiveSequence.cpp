#include "stdafx.h"
#include "LongestConsecutiveSequence.h"

#include <set>

//O(n)
int Solution::longestConsecutive(vector<int>& nums) {
	set<int> table;
	int localmax = 0, max = 0;

	// add all the integers to ordered set
	for (auto num : nums) {
		table.insert(num);
	}

	// for each element in the set, if there is no previous value 
	// (i.e. not a part of the sequence), then count all the consecutive 
	// integers that follow. This optimizes in that we don't loop through
	// every integer.
	for (auto x : table) {
		if (table.find(x - 1) == table.end()) {
			int num = x;
			localmax = 1;

			while (table.find(num + 1) != table.end()) {
				num++;
				localmax++;
			}

			max = localmax > max ? localmax : max;
		}
	}

	return max;
}