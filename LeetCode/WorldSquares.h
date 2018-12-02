#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    // prefix is to keep indexes of all words that have the prefix from root to current node 
    vector<int> prefix;
    TrieNode* childs[26];
    TrieNode () {
        memset(childs, 0, sizeof(childs));
    }
};

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words);
	TrieNode* build(vector<string>& words);
	void helper(vector<vector<string>>& ans, vector<string>& board, vector<string>& words, TrieNode* root, int row);
};