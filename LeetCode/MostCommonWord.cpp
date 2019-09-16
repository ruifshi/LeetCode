#include "stdafx.h"
#include "MostCommonWord.h"

#include <unordered_map>

// can also use a set as banned, then put map into a vector and sort
// output first word not in banned
string Solution::mostCommonWord(string paragraph, vector<string>& banned) {
	unordered_map<string, int> count;
	string ans;

	for (int i = 0; i < paragraph.length();) {
		string s;

		while (i < paragraph.length() && isalpha(paragraph[i])) {
			s += tolower(paragraph[i++]);
		}

		while (i < paragraph.length() && !isalpha(paragraph[i])) {
			i++;
		}

		count[s]++;
	}

	for (auto w : banned) count[w] = 0;

	int max = 0;
	for (auto w : count) {
		if (w.second > max) {
			ans = w.first;
			max = w.second;
		}
	}

	return ans;
}