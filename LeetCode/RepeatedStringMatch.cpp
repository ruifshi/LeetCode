#include "stdafx.h"
#include "RepeatedStringMatch.h"

using namespace std;

int repeatedStringMatch(string A, string B) {
	string C = A;
	int count = 1;

	while(C.length() < B.length()) {
		C += A;
		count++;
	}

	if(C.find(B) != string::npos) {
		return count;
	}

	C += A;

	if(C.find(B) != string::npos) {
		return count + 1;
	}

	return -1;
}