#include "stdafx.h"
#include "LongestSubstringK.h"

#include <map>

int Solution::lengthOfLongestSubstringKDistinct(string s, int k) {
 	int front = 0, end = 0, max = 0;
	map<char, int> dict;

	while(end < s.size()) {
		char c = s[end];
		if(dict.find(c) != dict.end()) {
			dict[c]++;
		}
		else {
			dict[c] = 1;
		}

		while(dict.size() > k) {
			c = s[front];
			if(--dict[c] == 0) {
				dict.erase(c);
			}
			front++;
		}
		max = max > (end - front + 1) ? max : (end - front + 1);
		end++;
	}

	return max;
}