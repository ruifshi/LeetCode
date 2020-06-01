#include "stdafx.h"
#include "LongestSubstringK.h"

#include <unordered_map>

// O(n)
int Solution::lengthOfLongestSubstringKDistinct(string s, int k) {
 	int front = 0, end = 0, max = 0;
  unordered_map<char, int> dict;

	while(end < s.size()) {
		// use map to keep track of unique chars
		char c = s[end];
	  dict[c]++;


		// when we go over the unique char count, start
		// incrementing the pointer and poping chars
		while(dict.size() > k) {
			c = s[front];
			if(--dict[c] == 0) {
				dict.erase(c);
			}
			front++;
		}

		// calculate the current max
		max = max > (end - front + 1) ? max : (end - front + 1);
		end++;
	}

	return max;
}