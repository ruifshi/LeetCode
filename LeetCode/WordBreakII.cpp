#include "stdafx.h"
#include "WordBreakII.h"

// O(n^3)
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

/* DP
public class Solution {
	public List<String> wordBreak(String s, Set<String> wordDict) {
		LinkedList<String>[] dp = new LinkedList[s.length() + 1];
		LinkedList<String> initial = new LinkedList<>();
		initial.add("");
		dp[0] = initial;
		for (int i = 1; i <= s.length(); i++) {
			LinkedList<String> list = new LinkedList<>();
			for (int j = 0; j < i; j++) {
				if (dp[j].size() > 0 && wordDict.contains(s.substring(j, i))) {
					for (String l : dp[j]) {
						list.add(l + (l.equals("") ? "" : " ") + s.substring(j, i));
					}
				}
			}
			dp[i] = list;
		}
		return dp[s.length()];
	}
}
*/