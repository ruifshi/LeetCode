#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int numSquarefulPerms(vector<int>& A);
	void dfs(int x, int left);

	unordered_map<int, int> count;
	unordered_map<int, unordered_set<int>> cand;
	int res = 0;
};