#include "stdafx.h"

#include <string>

using namespace std;

string IntToString(int x) {
	// TODO - you fill in here.
	string s;
	bool is_negative = false;

	if (x < 0) is_negative = true;

	// add characters in reverse
	do {
		s += '0' + abs(x % 10);
		x /= 10;
	} while (x);

	if (is_negative) s += '-';

	std::reverse(s.begin(), s.end());

	return s;
}
int StringToInt(const string& s) {
	// TODO - you fill in here.
	int num = 0, start = 0;;
	bool negative = false;

	if (s[0] == '-') {
		start = 1;
		negative = true;
	}
	else if (s[0] == '+') {
		start = 1;
	}

	for (int i = start; i < s.size(); i++) {
		num = num * 10 + (s[i] - '0');
	}

	if (negative) num = -num;

	return num;
}