#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string>& words);
	bool is_palindrome(string& s, int start, int end);
};