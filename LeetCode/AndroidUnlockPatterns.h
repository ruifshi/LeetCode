#include <vector>

using namespace std;

class Solution {
public:
    int numberOfPatterns(int m, int n);
	int helper(vector<bool> visited, vector<vector<int>> skiptable, int current, int remain); 
};