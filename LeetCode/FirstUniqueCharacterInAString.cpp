#include "stdafx.h"
#include "FirstUniqueCharacterInAString.h"

#include <unordered_map>

// O(n)
int Solution::firstUniqChar(string s) {
	/*
	unordered_map<char, pair<int, int>> table;
	int index = s.size();

	for(int i = 0; i < s.size(); i++) {
		table[s[i]].first = i;
		table[s[i]].second++;
	}

	for(auto x : table) {
		if(x.second.second == 1) {
			index = index < x.second.first ? index : x.second.first;
		}
	}

	return index == s.size() ? -1 : index;
	*/

    vector<int> v(26, 0);

	// count number of chars for each letter
	for (auto u : s) {
		v[u - 'a'] += 1;
	}

	// iterate through string and return the first
	// index that is more than one char
	for (int i = 0; i < s.size(); i++) {
		if (v[s[i] - 'a'] == 1) {
			return i;
		}
	}

    return -1;
}