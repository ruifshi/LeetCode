#include "stdafx.h"
#include "LongestPalindromicSubstring.h"
#include <algorithm>

// O(n^2)
string Solution::longestPalindrome(string s) {
	if(s.size() == 0 || s == "") {
		return "";
	}

	int start = 0, maxlen = 0;

	// iterate through the string and find the largest size
	// of palindrome for each char.
	for(int i = 0; i < s.length(); i++) {
		// need to expand around i for odd number of char
        int len1 = expandAroundCenter(s, i, i);
		// need to expand around i+1 for even number of chars
		int len2 = expandAroundCenter(s, i, i+1);
		int len = max(len1, len2);
        if (len > maxlen) {
            start = i - (len - 1) / 2;
			maxlen = len;
        }
	}

	return s.substr(start, maxlen);
}

int Solution::expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}