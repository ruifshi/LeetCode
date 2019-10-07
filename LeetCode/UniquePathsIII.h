#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsIII(vector<vector<int>>& grid);
	int paths(vector<vector<int>> &grid, int x, int y, int x_end, int y_end, int covered, int required);
};