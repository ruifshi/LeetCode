#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits);
	void letterCombinationsHelper(string &digits, string &curr, int curr_digit, vector<string> &ans);
};