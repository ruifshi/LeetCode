#include "stdafx.h"
#include "FruitIntoBaskets.h"

#include <unordered_map>
#include <algorithm>

// O(n)
int Solution::totalFruit(vector<int>& tree) {
	unordered_map<int, int> table;
	int maxSize = 0, i = 0;

	// use a sliding window with 2 pointers where we use a map
	// to keep track of the unique numbers. If a new
	// unique number comes, we need to delete the first
	// number in our map to keep track of the new one and increment
	// the start window.
	for (int j = 0; j < tree.size(); j++) {
		table[tree[j]]++;
		while (table.size() > 2) {
			table[tree[i]]--;
			if (table[tree[i]] == 0) {
				table.erase(tree[i]);
			}
			i++;
		}
		maxSize = max(maxSize, j - i + 1);
	}

	return maxSize;
}