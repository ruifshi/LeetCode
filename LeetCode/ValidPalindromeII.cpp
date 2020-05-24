#include "stdafx.h"
#include "ValidPalindromeII.h"

bool Solution::validPalindrome(string s) {
	int i = 0, j = s.size() - 1;

	while (i < j) {
		if (s[i] != s[j]) {
			// check if removing the left or right chars results
			// in a palindrome in the middle
			int i1 = i, j1 = j - 1, i2 = i + 1, j2 = j;

			while (i1 < j1 && s[i1] == s[j1]) i1++, j1--;
			while (i2 < j2 && s[i2] == s[j2]) i2++, j2--;

			return i1 >= j1 || i2 >= j2;
		}

		i++, j--;
	}

	return true;
}