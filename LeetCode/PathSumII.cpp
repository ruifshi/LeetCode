#include "stdafx.h"
#include "PathSumII.h"

vector<vector<int>> Solution::pathSum(TreeNode* root, int sum) {
	vector<vector<int> > paths;
	vector<int> path;
	findPaths(root, sum, path, paths);
	return paths;
}

// backtrack, if the current paths isn't correct, then remove the node after traversing and move on to next
// If the current path reaches last node and sum is found, then push the path to the ans vector
void Solution::findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
	if (!node) return;
	path.push_back(node->val);
	if (!(node->left) && !(node->right) && sum == node->val)
		paths.push_back(path);
	findPaths(node->left, sum - node->val, path, paths);
	findPaths(node->right, sum - node->val, path, paths);
	path.pop_back();
}