#include "stdafx.h"
#include "ConcatenatedWords.h"

#include <algorithm>

bool comp(string &a, string &b) {
	return a.size() < b.size();
}

vector<string> Solution::findAllConcatenatedWordsInADict(vector<string>& words) {
	vector<string> ans;
	unordered_set<string> dict;

	sort(words.begin(), words.end(), comp);

	for (int i = 0; i < words.size(); i++) {
		if (wordCheck(words[i], dict)) {
			ans.push_back(words[i]);
		}

		dict.insert(words[i]);
	}

	return ans;
}

bool Solution::wordCheck(string &s, unordered_set<string> &dict) {
	if (s.empty()) {
		return false;
	}

	int s_size = s.size();
	vector<bool> dp(s_size + 1, false);
	dp[0] = true; // NULL string

	for (int i = 1; i <= s_size; i++) {
		for (int j = 0; j < i; j++) {
			//check that current substring starts at the boundary of the previously
			//found word
			//dp = true means a word in the dict is a substr of s at that point
			if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
				dp[i] = true;
				break;
			}
		}
	}

	return dp[s_size];
}