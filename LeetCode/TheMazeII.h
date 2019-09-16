#include <vector>

using namespace std;

class Solution {
public:
	int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination);
	void dfs(vector<vector<int>>& maze, vector<int> start, vector<vector<int>>& distance);
};