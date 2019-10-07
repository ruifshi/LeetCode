#include <vector>

using namespace std;

class Solution {
public:
	int cutOffTree(vector<vector<int>>& forest);
	int next_step(vector<vector<int>>& forest, int sr, int sc, int er, int ec);
};