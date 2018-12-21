#include "stdafx.h"
#include "GenerateParentheses.h"

vector<string> Solution::generateParenthesis(int n) {
	vector<string> ans;
	string s;
	generateParenthesisHelper(ans, s, 0, 0, n);
	return ans;
}

void Solution::generateParenthesisHelper(vector<string> &ans, string curr, int open, int close, int max) {
	// end condition is that current string is 2*max since max is number of pairs
	if (curr.size() == 2*max) {
		ans.push_back(curr);
		return;
	}

	// start with open brace and iterate
	// the pick/unpick sequence will create the alternation
	if (open < max) {
		generateParenthesisHelper(ans, curr + "(", open + 1, close, max);
	}

	// choose close if there is one missing
	if (close < open) {
		generateParenthesisHelper(ans, curr + ")", open, close + 1, max);
	}

	return;
}