#include "stdafx.h"
#include "LicenseKeyFormat.h"

#include <string>

using namespace std;

// O(n)
string Solution::licenseKeyFormatting(string S, int K) {
	string out;
	int count = K;

	if(S[0] == '\0') {
		return NULL;
	}

	// convert all chars to upper case
	for(int i = 0; i < S.size(); i++) {
		if(S[i] != '-') {
		  out += toupper(S[i]);
		}
	}

	// for every k chars, add a '-'
	for(int i = out.size() - 1; i >= 0; i--) {
		count--;
		if(count == 0 && i != 0) {
			out.insert(i, "-");
			count = K;
		}
	}

	return out;
}