#include "stdafx.h"
#include "WordBreakII.h"

// O(n^3)
/*
vector<string> Solution::wordBreakII(string s, vector<string>& wordDict) {
	unordered_set<string> Dict;

	for (int i = 0; i < wordDict.size(); i++) {
		Dict.insert(wordDict[i]);
	}

	return helper(s, Dict);
}

vector<string> Solution::helper(string s, unordered_set<string>& word)
{
	vector<string>res;
	if (table.find(s) != table.end()) {
		return table[s];
	}

	if (word.find(s) != word.end()) {
		res.push_back(s);
	}

	for (int i = s.length() - 1; i >= 0; i--) {
		if (word.find(s.substr(i)) != word.end()) {
			string next = s.substr(i);
			vector<string>ans = helper(s.substr(0, i), word);
			for (int j = 0; j < ans.size(); j++) {
				ans[j] += " " + next;
			}
			res.insert(res.begin(), ans.begin(), ans.end());
		}
	}
	table[s] = res;
	return res;
}
*/
vector<string> Solution::wordBreakII(string s, vector<string>& wordDict) {
	vector<vector<string>> dp(s.length() + 1);
	vector<string> initial;
	initial.push_back("");
	dp[0] = initial;

	unordered_set<string> Dict;

	for (int i = 0; i < wordDict.size(); i++) {
		Dict.insert(wordDict[i]);
	}

	for (int i = 1; i <= s.length(); i++) {
		vector<string> list;
		for (int j = 0; j < i; j++) {
			if (dp[j].size() > 0 && Dict.find(s.substr(j, i-j)) != Dict.end()) {
				for (string l : dp[j]) {
					list.push_back(l + (l == "" ? "" : " ") + s.substr(j, i-j));
				}
			}
		}
		dp[i] = list;
	}
	return dp[s.length()];
}