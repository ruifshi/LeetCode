#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n);
	void generateParenthesisHelper(vector<string> &ans, string curr, int open, int close, int max);
};