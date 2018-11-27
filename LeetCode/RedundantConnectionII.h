#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges);
	bool checkCycle(int v);

	unordered_map<int, int> path;
};