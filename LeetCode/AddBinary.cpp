#include "stdafx.h"
#include "AddBinary.h"

string Solution::addBinary(string a, string b) {
	int i = a.size() - 1, j = b.size() - 1, carry = 0;
	string s;

	while (i >= 0 || j >= 0 || carry) {
		carry += i >= 0 ? a[i--] - '0' : 0;
		carry += j >= 0 ? b[j--] - '0' : 0;

		s += char(carry % 2 + '0');
		carry /= 2;
	}

	reverse(s.begin(), s.end());

	return s;
}