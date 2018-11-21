#include "stdafx.h"
#include "OneEditDist.h"

bool Solution::isOneEditDistance(string s, string t) {
	int slen = s.size();
	int tlen = t.size();

	if(abs(slen - tlen) > 1 || (slen == 0 && tlen == 0) || s.compare(t) == 0) {
		return false;
	}

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