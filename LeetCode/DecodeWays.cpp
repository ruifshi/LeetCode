#include "stdafx.h"
#include "DecodeWays.h"

#include <vector>

// O(n)
int Solution::numDecodings(string s) {
	return helper_dp(s);
}

int Solution::helper_dp(string s) {
	int size = s.size();

	if (size == 0 || s.at(0) == '0') {
		return 0;
	}
	else if (size == 1) {
		return 1;
	}

	vector<int> ways(size + 1, 0);

	ways[0] = 1;	// Null string
	ways[1] = 1;	// valid first char
	
	for (int i = 2; i <= size; i++) {
		if (s.at(i - 1) > '0') {
			ways[i] = ways[i - 1];
		}

		if (s.at(i - 2) == '1' || (s.at(i - 2) == '2' && s.at(i - 1) < '7')) {
			ways[i] += ways[i-2];
		}
	}

	return ways[size];
}

int Solution::helper_recur(string s) { 
	if(s == "") {
		return 1;
	}

	if(s.at(0) == '0') {
		return 0;
	}

	int ways = helper_recur(s.substr(1, s.size()-1));
	
	if(stoi(s.substr(0,2)) < 27 && s.size() >= 2) {
		ways += helper_recur(s.substr(2, s.size()-1));
	}

	return ways;
}