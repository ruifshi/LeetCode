#include "stdafx.h"
#include "PartitionLabels.h"

/*
Let's try to repeatedly choose the smallest left-justified partition. 
Consider the first label, say it's 'a'. The first partition must include it, 
and also the last occurrence of 'a'. However, between those two occurrences of 'a', 
there could be other labels that make the minimum size of this partition bigger. 
For example, in "abccaddbeffe", the minimum first partition is "abccaddb". 
This gives us the idea for the algorithm: For each letter encountered, 
process the last occurrence of that letter, extending the current partition 
[anchor, j] appropriately.
*/
vector<int> Solution::partitionLabels(string S) {
	int last[26];
	vector<int> ans;

	for (int i = 0; i < S.length(); i++) {
		last[S[i] - 'a'] = i;
	}

	int left = 0, right = 0;

	for (int i = 0; i < S.length(); i++) {
		right = right > last[S[i] - 'a'] ? right : last[S[i] - 'a'];
		if (i == right) {
			ans.push_back(i - left + 1);
			left = i + 1;
		}
	}

	return ans;
}