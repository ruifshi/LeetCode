#include "stdafx.h"
#include "RemoveInvalidParentheses.h"

#include <unordered_set>

bool isValidStr(string s) {
	int cnt = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			cnt++;
		else if (s[i] == ')')
			cnt--;
		if (cnt < 0)
			return false;
	}
	return (cnt == 0);
}

void removeInvalidParenthesesHelper(string s, int begin, unordered_set<string> &wordSet, int left, int right) {
	if (wordSet.find(s) != wordSet.end()) return;

	if (left == 0 && right == 0 && isValidStr(s)) {
		wordSet.insert(s);
		return;
	}

	for (int i = begin; i < s.size(); i++) {
		if (s[i] == '(' && left > 0 && right == 0) {
			string tmp = s;
			tmp.erase(i, 1);
			removeInvalidParenthesesHelper(tmp, i, wordSet, left - 1, right);
		}
		else if (s[i] == ')' && right > 0) {
			string tmp = s;
			tmp.erase(i, 1);
			removeInvalidParenthesesHelper(tmp, i, wordSet, left, right - 1);
		}
	}
}

vector<string> Solution::removeInvalidParentheses(string s) {
	unordered_set<string> wordSet;
	int left = 0, right = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') left++;
		if (s[i] == ')') {
			if (left == 0)
				right++;
			else
				left--;
		}
	}

	removeInvalidParenthesesHelper(s, 0, wordSet, left, right);

	vector<string> out;

	for (auto x : wordSet) out.push_back(x);

	return out;
}