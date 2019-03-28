#include "stdafx.h"
#include "WordLadder.h"

#include <unordered_set>
#include <queue>

/*
Since only one letter can be changed at a time, if we start from "hit", we can only change to those 
words which have exactly one letter different from it (in this case, "hot"). Putting in graph-theoretic terms, 
"hot" is a neighbor of "hit". The idea is simpy to start from the beginWord, then visit its neighbors, then 
the non-visited neighbors of its neighbors until we arrive at the endWord. This is a typical BFS structure.
*/
int Solution::ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	unordered_set<string> dict(wordList.begin(), wordList.end());
	queue<string> todo;
	todo.push(beginWord);
	int ladder = 1;
	while (!todo.empty()) {
		int n = todo.size();
		for (int i = 0; i < n; i++) {
			string word = todo.front();
			todo.pop();
			if (word == endWord) {
				return ladder;
			}
			dict.erase(word);
			for (int j = 0; j < word.size(); j++) {
				char c = word[j];
				for (int k = 0; k < 26; k++) {
					word[j] = 'a' + k;
					if (dict.find(word) != dict.end()) {
						todo.push(word);
					}
				}
				word[j] = c;
			}
		}
		ladder++;
	}
	return 0;
}