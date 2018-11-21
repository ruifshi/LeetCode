#include "stdafx.h"
#include "ValidPalindrome.h"

bool Solution::isPalindrome(string s) {
	string t;

	for(int i = 0; i < s.size(); i++) {
		if((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
			t += toupper(s[i]);
		}
	}

	int front = 0, end = t.size() - 1;

	while(front < end) {
		if(t[front] == t[end]) {
			front++;
			end--;
		}
		else
		{
			return false;
		}
	}

	return true;
}