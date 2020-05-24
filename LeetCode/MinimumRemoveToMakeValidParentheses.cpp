#include "stdafx.h"
#include "MinimumRemoveToMakeValidParentheses.h"

#include <stack>
#include <set>

string Solution::minRemoveToMakeValid(string s) {
	stack<int> indices;
	//set<int> indices_to_remove;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			indices.push(i);
		}
		else if (s[i] == ')') {
			if (indices.empty()) {
				//indices_to_remove.insert(i);
				s[i] = '*';
			}
			else {
				indices.pop();
			}
		}
	}

	string ans;

	while (!indices.empty()) {
		//indices_to_remove.insert(indices.top());
		s[indices.top()] = '*';
		indices.pop();
	}

	for (int i = 0; i < s.size(); i++) {
		//if (indices_to_remove.find(i) == indices_to_remove.end()) {
		if(s[i] != '*') {
			ans += s[i];
		}
	}

	return ans;
}