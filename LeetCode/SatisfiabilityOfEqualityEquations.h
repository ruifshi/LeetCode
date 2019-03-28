#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool equationsPossible(vector<string>& equations);
	void dfsVisit(int u, int colorNumber);

	vector<bool> visited;
	vector<int> color;
	vector<vector<int>> adj;
};