#include "stdafx.h"

#include <vector>
#include <map>
#include <set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	vector<int> ans;
	map<TreeNode*, TreeNode*> parent;  // son=>parent  
	set<TreeNode*> visit;    //record visied node

	vector<int> distanceK(TreeNode* root, TreeNode* target, int K);
	void findParent(TreeNode* node);
	void dfs(TreeNode* node, int K);
};