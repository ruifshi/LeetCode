#include "stdafx.h"
#include "AddAndSearchWord.h"

#include <queue>

/** Initialize your data structure here. */
WordDictionary::WordDictionary() {
	root = new TrieNode;
}

/** Adds a word into the data structure. */
void WordDictionary::addWord(string word) {
	TrieNode *node = root;
	for (int i = 0; i < word.size(); i++) {
		if (!node->next[word[i]]) {
			node->next[word[i]] = new TrieNode();
		}

	  node = node->next[word[i]];
	}

	node->end = true;

	return;
}

bool WordDictionary::searchHelper(const string &word, int pos, TrieNode *node) {
	if (pos == word.size()) return node->end;
	if (word[pos] != '.') {
		node = node->next[word[pos]];
		return node ? searchHelper(word, pos + 1, node) : false;
	}
	for (auto x : node->next)
		if (x.second && searchHelper(word, pos + 1, x.second))
			return true;
	return false;
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool WordDictionary::search(string word) {
	return searchHelper(word, 0, root);
}

/*
bool WordDictionary::search(string word) {
	TrieNode* node = root;
	queue<TrieNode*> q;

	q.push(node);

	for (int i = 0; i < word.size(); i++) {
		int q_size = q.size();

		if (q_size == 0) return false;

		for (int j = 0; j < q_size; j++) {
			node = q.front();
			q.pop();

			if (word[i] != '.') {
				if (node->next[word[i]]) {
					if (node->next[word[i]]->end) return true;

					q.push(node->next[word[i]]);
				}
			}
			else {
				for (auto x : node->next) {
					if (x.second) {
						if (x.second->end) return true;

						q.push(x.second);
					}
				}
			}
		}
	}

	return false;
}
*/