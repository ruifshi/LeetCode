#include "stdafx.h"
#include "WordBreak.h"

#include <set>

bool Solution::wordBreak(string s, vector<string>& wordDict) {
	set<string> Dict;

	for (int i = 0; i < wordDict.size(); i++) {
		Dict.insert(wordDict[i]);
	}

	vector<bool> table(s.size()+1, false);

	table[0] = true;

	for (int i = 1; i <= s.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (table[j] && Dict.find(s.substr(j, i - j)) != Dict.end()) {
				table[i] = true;
				break;
			}
		}
	}

	return table[s.size()];

	/*Trie Solution doesn't work if multiple answers in dict
	TrieNode* root = buildTries(wordDict);
	TrieNode* p = root;
	vector<bool> found(wordDict.size(), false);

	for (int i = 0; i < s.size(); i++) {
		if (p->children[s.at(i)] != NULL) {
			if (!p->children[s.at(i)]->end && i == s.size() - 1) {
				return false;
			}

			if (p->children[s.at(i)]->end && !found[p->children[s.at(i)]->index]) {
				found[p->children[s.at(i)]->index] = true;
				p = root;
			}
			else {
				p = p->children[s.at(i)];
			}
		}
		else
		{
			return false;
		}
	}

	return true;
	*/
}

TrieNode* Solution::buildTries(vector<string>& wordDict) {
	TrieNode *root = new TrieNode();
	for (int i = 0; i < wordDict.size(); i++) {
		TrieNode *p = root;
		for (int j = 0; j < wordDict[i].size(); j++) {
			if (p->children[wordDict[i][j]] == NULL) {
				p->children[wordDict[i][j]] = new TrieNode();
			}
			p = p->children[wordDict[i][j]];
		}
		p->index = i;
		p->end = true;
	}

	return root;
}