#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites);
	bool dfs_is_cycle(vector<vector<int>> graph, int node, vector<bool> visited, vector<bool> onstack);
};