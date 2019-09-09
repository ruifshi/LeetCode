#include "stdafx.h"
#include "PalindromeNumber.h"

#include <string>

using namespace std;

bool Solution::isPalindrome(int x) {
	if (x < 0 || (x % 10 == 0 && x != 0)) {
		return false;
	}

	string s = to_string(x);
	int left = 0;
	int right = s.length() - 1;

	while (left <= right) {
		if (s[left++] == s[right--]) {
			continue;
		}
		else {
			return false;
		}
	}

	return true;
}