#include "stdafx.h"
#include "OneEditDist.h"

// O(n)
bool Solution::isOneEditDistance(string s, string t) {
	int slen = s.size();
	int tlen = t.size();

	// if size diff is more than 2, return
	if(abs(slen - tlen) > 1 || (slen == 0 && tlen == 0) || s.compare(t) == 0) {
		return false;
	}

	// if the length is the same, then see if there is only one char diff
	if(slen == tlen) {
		int count = 0;
		for(int i = 0; i < slen; i++) {
			if(s[i] != t[i]) {
				count++;
			}
		}

		if(count > 1) {
			return false;
		}
		else {
			return true;
		}
	}

	// find the longer string and iterate. Check each char one by one
	// and keep an index diff to keep track. If diff becomes greater than
	// 1, return false;
	int i = 0, diff = 0;
	string longer;
	string shorter;

	if(slen > tlen) {
		longer = s;
		shorter = t;
	}
	else {
		longer = t;
		shorter = s;
	}

	while(i < longer.size()) {
		if(longer[i + diff] == shorter[i]) {
			i++;
		}
		else {
			diff++;
			if(diff > 1) {
				return false;
			}
		}
	}

	return true;
}