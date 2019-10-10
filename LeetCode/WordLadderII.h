#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList);
	void dfs_wordladderii(const string & end_word,
		const string & cur_word,
		const unordered_map<string, vector<string>>& children,
		vector<string> & line,
		vector<vector<string>> & res);
};