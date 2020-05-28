#include "stdafx.h"
#include "GroupShiftedStrings.h"

#include <unordered_map>
#include <algorithm>

// use distance between chars as the key
string findKey(string& s) {
	string t;
	int n = s.length();
	for (int i = 1; i < n; i++) {
		int diff = s[i] - s[i - 1];
		if (diff < 0) diff += 26;
		t += diff;
	}
	return t;
}

vector<vector<string>> Solution::groupStrings(vector<string>& strings) {
	unordered_map<string, vector<string> > mp;
	for (string s : strings)
		mp[findKey(s)].push_back(s);
	vector<vector<string> > groups;
	for (auto m : mp) {
		vector<string> group = m.second;
		sort(group.begin(), group.end());
		groups.push_back(group);
	}
	return groups;
}