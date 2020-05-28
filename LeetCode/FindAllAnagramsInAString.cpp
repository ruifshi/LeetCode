#include "stdafx.h"
#include "FindAllAnagramsInAString.h"

#include <unordered_map>

vector<int> Solution::findAnagrams(string s, string p) {
	unordered_map<char, int> s_in;
	unordered_map<char, int> p_in;
	vector<int> ans;

	for (auto c : p) {
		p_in[c]++;
	}

	int p_size = p.size();
	for (int i = 0, start = 0; i < s.size(); i++) {
		s_in[s[i]]++;

		if (i >= p_size) {
			if (s_in[s[start]] == 1) {
				s_in.erase(s[start]);
			}
			else {
				s_in[s[start]]--;
			}

			start++;
		}

		if (s_in == p_in) {
			ans.push_back(start - 1);
		}
	}

	return ans;
}