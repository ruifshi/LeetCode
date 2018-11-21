#include "stdafx.h"
#include "LicenseKeyFormat.h"

#include <string>

using namespace std;

string Solution::licenseKeyFormatting(string S, int K) {
	string out;
	int count = K;

	if(S[0] == '\0') {
		return NULL;
	}

	for(int i = 0; i < S.size(); i++) {
		if(S[i] != '-') {
		  out += toupper(S[i]);
		}
	}

	for(int i = out.size() - 1; i >= 0; i--) {
		count--;
		if(count == 0 && i != 0) {
			out.insert(i, "-");
			count = K;
		}
	}

	return out;
}