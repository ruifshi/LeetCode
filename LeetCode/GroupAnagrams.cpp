#include "stdafx.h"
#include "GroupAnagrams.h"

#include <unordered_map>
#include <algorithm>

vector<vector<string>> Solution::groupAnagrams(vector<string>& strs) {
	unordered_map<string, vector<string>> mp;
	for (string s : strs) {
		string t = s;
		sort(t.begin(), t.end());	//you can sort strings to be alphabetical
		mp[t].push_back(s);			//all anagrams will have same key once sorted
	}
	vector<vector<string>> anagrams;
	for (auto p : mp) {
		anagrams.push_back(p.second);
	}
	return anagrams;
}