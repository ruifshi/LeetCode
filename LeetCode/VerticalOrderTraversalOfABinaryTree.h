#include "stdafx.h"

#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void dfs(TreeNode* root, int hd, map<int, vector<int>> &m);
	vector<vector<int>> verticalTraversal(TreeNode* root);
};