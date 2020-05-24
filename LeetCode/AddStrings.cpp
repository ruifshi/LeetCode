#include "stdafx.h"
#include "AddStrings.h"

string Solution::addStrings(string num1, string num2) {
	int i = num1.size() - 1;
	int j = num2.size() - 1;
	int carry = 0;
	string res = "";
	while (i >= 0 || j >= 0 || carry) {
		int sum = carry;
		if (i >= 0) { sum += (num1[i] - '0');i--; }
		if (j >= 0) { sum += (num2[j] - '0');j--; }
		carry = sum / 10;
		sum = sum % 10;
		res += sum + '0';
	}
	reverse(res.begin(), res.end());
	return res;
}