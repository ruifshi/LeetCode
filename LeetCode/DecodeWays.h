#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s);
	int helper_recur(string s);
	int helper_dp(string s);
};