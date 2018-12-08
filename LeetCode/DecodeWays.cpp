#include "stdafx.h"
#include "DecodeWays.h"

int Solution::numDecodings(string s) {
	return helper(s);
}

int Solution::helper(string s) {
	if(s == "") {
		return 1;
	}

	if(s == "0") {
		return 0;
	}

	int ways = helper(s.substr(1, s.size()-2));
	
	if(stoi(s.substr(0,2)) < 27) {
		ways += helper(s.substr(2, s.size()-3));
	}

	return ways;
}