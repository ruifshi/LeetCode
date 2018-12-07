#include <vector>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix);
	void helper(vector<vector<int>>& matrix, vector<vector<bool>>& ocean, int previous, int row, int col);
};