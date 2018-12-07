#include <vector>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid);
	bool helper(vector<vector<int>>& grid, vector<vector<int>>& hits, vector<vector<int>>& dist, int buildings, int row, int col);
};