#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<string> wordBreakII(string s, vector<string>& wordDict);
	vector<string>helper(string s, unordered_set<string>& word);
	unordered_map<string, vector<string>>table;
};