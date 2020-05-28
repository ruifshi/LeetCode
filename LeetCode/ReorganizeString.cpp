#include "stdafx.h"
#include "ReorganizeString.h"

#include <vector>
#include <algorithm>

string Solution::reorganizeString(string S) {
	vector<int> table(26);
	int n = S.size();

	for (auto c : S) table[c - 'a']++;

	vector<pair<int, char>> charCount;
	for (int i = 0; i < 26; i++) {
		if (table[i] > (n + 1) / 2) return ""; //means that 1 more than half of the letters are the same so impossible
		if (table[i]) charCount.push_back(make_pair(table[i], i + 'a'));
	}

	sort(charCount.begin(), charCount.end());

	string sorted;
	for (int i = charCount.size() - 1; i >= 0; i--) {
		sorted += string(charCount[i].first, charCount[i].second);
	}

	string ans;

	for (int i = 0, j = (n - 1) / 2 + 1; i < (n - 1) / 2 + 1; i++, j++) {
		ans += sorted[i];
		if(j < n) ans += sorted[j];
	}

	return ans;
}