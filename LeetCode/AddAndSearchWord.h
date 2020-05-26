#pragma once
#include <string>
#include <unordered_map>

using namespace std;

class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary();

	/** Adds a word into the data structure. */
	void addWord(string word);

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word);

private:
	struct TrieNode {
		bool end;
		unordered_map<char, TrieNode*> next;

		TrieNode() { end = false; }
	};

	TrieNode *root;

	bool searchHelper(const string &word, int pos, TrieNode *node);
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */