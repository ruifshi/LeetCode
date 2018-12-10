#include <string>
#include <vector>
#include <map>

using namespace std;

struct TrieNode {
	map <char, TrieNode*> children;
	int index;
	bool end;
	TrieNode() {
		index = 0, end = false;
	}
};

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict);
	TrieNode* buildTries(vector<string>& wordDict);
};