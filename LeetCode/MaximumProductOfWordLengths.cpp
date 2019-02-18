#include "stdafx.h"
#include "MaximumProductOfWordLengths.h"

#include <algorithm>

int Solution::maxProduct(vector<string>& words) {
	vector<int> mask(words.size());
	int result = 0;
	for (int i = 0; i < words.size(); ++i) {
		// create bit mask for a word's chars
		for (char c : words[i])
			mask[i] |= 1 << (c - 'a');
		// check all previous words against current word to see if there are no common chars
		for (int j = 0; j < i; ++j)
			// if no common chars, then we can multiple the sizes
			if (!(mask[i] & mask[j]))
				result = max(result, int(words[i].size() * words[j].size()));
	}
	return result;
}