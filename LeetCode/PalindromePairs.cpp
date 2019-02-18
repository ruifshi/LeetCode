#include "stdafx.h"
#include "PalindromePairs.h"

#include <unordered_map>

// O(words * size of word * 2 * size of word)
vector<vector<int>> Solution::palindromePairs(vector<string>& words) {
	vector<vector<int>> result;
	unordered_map<string, int> dict;
	// put words in the dictionary to be searched later
	for (int i = 0; i < words.size(); i++) {
		dict[words[i]] = i;
	}
	for (int i = 0; i < words.size(); i++) {
		for (int j = 0; j <= words[i].length(); j++) {
			//check the suffix word
			// iterate through the word to find a substring that is a palindrome
			// the rest of the substring will need to be repeated in reverse to create
			// a final palindrome. Search the dictionary to see if such a word exists
			if (is_palindrome(words[i], j, words[i].size() - 1)) {
				/** the suffix word can be null to all the word **/
				string suffix = words[i].substr(0, j);
				reverse(suffix.begin(), suffix.end());
				if (dict.find(suffix) != dict.end() && i != dict[suffix]) {
					result.push_back({ i, dict[suffix] });
				}
			}
			//check the prefix word 
			if (j > 0 && is_palindrome(words[i], 0, j - 1)) {
				string prefix = words[i].substr(j);
				reverse(prefix.begin(), prefix.end());
				if (dict.find(prefix) != dict.end() && dict[prefix] != i) {
					result.push_back({ dict[prefix], i });
				}
			}
		}
	}
	return result;
}

bool Solution::is_palindrome(string& s, int start, int end) {
	while (start < end) {
		if (s[start++] != s[end--]) {
			return false;
		}
	}
	return true;
}