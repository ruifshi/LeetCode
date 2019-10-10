#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words);
	bool wordCheck(string &s, unordered_set<string> &dict);
};