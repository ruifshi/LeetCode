#include "stdafx.h"
#include "BasicCalculatorIII.h"

#include <vector>
#include <algorithm>

using namespace std;

int Solution::calculate3(string s) {
	int i = 0;
	return parseExpr(s, i);
}

int Solution::parseExpr(string& s, int& i) {
	vector<int> nums;
	char op = '+';
	for (; i < s.length() && op != ')'; i++) {
		if (s[i] == ' ') continue;
		long n = s[i] == '(' ? parseExpr(s, ++i) : parseNum(s, i);
		switch (op) {
		case '+': nums.push_back(n); break;
		case '-': nums.push_back(-n); break;
		case '*': nums.back() *= n; break;
		case '/': nums.back() /= n; break;
		}
		if (i < s.length())                  // handle over flow of i in cases like "1 + 1"
			op = s[i];
	}
	int res = 0;
	for (int n : nums) res += n;
	return res;
}

int Solution::parseNum(string& s, int& i) {
	long n = 0;	// change to long to pass case like "0-2147483648"
	while (i < s.length() && isdigit(s[i]))
		n = s[i++] - '0' + 10 * n;
	return n;
}