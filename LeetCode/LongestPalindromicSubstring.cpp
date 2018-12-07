#include "stdafx.h"
#include "LongestPalindromicSubstring.h"

string Solution::longestPalindrome(string s) {
	if(s.size() == 0 || s == "") {
		return "";
	}

	int start = 0, maxlen = 0;

	for(int i = 0; i < s.length(); i++) {
        int len1 = expandAroundCenter(s, i, i);
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