#include <vector>
#include <string>
#include <map>

using namespace std;

struct TrieNode{
	map <char, TrieNode*> children;
	bool end;
	int index;
	TrieNode () {
		end = false, index = 0;
	}
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
	TrieNode* buildTrie(vector<string>& words);
	void helper(vector<vector<char>>& board, vector<string>& words, TrieNode *root, int row, int col, vector<vector<bool>> visited);

	vector<string> ans;
	vector<bool> found;
};