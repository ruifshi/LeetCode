#include "stdafx.h"
#include "ReverseString.h"

void Solution::reverseString(vector<char>& s) {
	char c;
	int i = 0, j = s.size() - 1;

	while (i < j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}

	return;
}