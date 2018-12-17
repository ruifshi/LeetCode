#include "stdafx.h"
#include "RepeatedStringMatch.h"

using namespace std;

//O(n)
int repeatedStringMatch(string A, string B) {
	string C = A;
	int count = 1;

	// A needs to be at least as large as B for B
	// to be a substring of A
	while(C.length() < B.length()) {
		C += A;
		count++;
	}

	// Return count if B is found
	if(C.find(B) != string::npos) {
		return count;
	}

	// If B is not found it means that A may have just
	// missed a few more chars as B can start from anywhere
	// inside A. Duplicate one more time
	C += A;

	if(C.find(B) != string::npos) {
		return count + 1;
	}

	// If still can't be found, then that means B doesn't
	// exist in A.
	return -1;
}