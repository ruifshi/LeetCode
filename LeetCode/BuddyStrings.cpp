#include "stdafx.h"
#include "BuddyStrings.h"

bool Solution::buddyStrings(string A, string B) {
	int count = 0;
	int mask = 0;
	int bitcount = 0;
	int check[2];

	if (A.length() != B.length()) return false;
	if ((A.length() == 0) || (A.length() > 20000)) return false;

	// If there are more than 2 characters different, then you can't swap
	// The ask checks are repeats in characters, which can be swapped
	// Also save the indices of the 2 chars that are different to be 
	// checked later
	for (int i = 0; i < A.length(); i++)
	{
		if (A[i] != B[i]) {
			if (count < 2) {
				check[count] = i;
			}
			count++;
		}
		mask |= 1 << A[i] - 'a';
		if (count > 2) return false;
	}

	// If there are repeating chars, then the number of the mask set
	// is smaller than the length of the string
	if (count == 0) {
		while (mask) {
			mask &= mask - 1;
			bitcount++;
		}
	}

	if ((count == 0) && (bitcount != A.length())) {
		return true;
	}

	if (count == 2 && A[check[0]] == B[check[1]] && A[check[1]] == B[check[0]]) {
		return true;
	}
	else {
		return false;
	}
}
