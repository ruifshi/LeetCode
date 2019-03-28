#include "stdafx.h"
#include "FlipBinaryTreeToMatchPreorderTraversal.h"

using namespace std;

//O(number of nodes)
vector<int> Solution::flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
	return dfs(root, voyage) ? res : vector<int>{ -1 };
}

bool Solution::dfs(TreeNode* node, vector<int>& voyage) {
	// base case NULL can always be flipped
	if (!node) return true;

	// base case where you can't flip and vals are different
	if (node->val != voyage[i++]) return false;

	// traverse left and right nodes when values are not equal
	// we can just do pre-order traversal and verify that the current node value matches the current voyage value. 
	// Also, we check if the next voyage value matches the left child value; if it does not - we flip left and right child and continue.
	if (node->left && node->left->val != voyage[i]) {
		res.push_back(node->val);
		return dfs(node->right, voyage) && dfs(node->left, voyage);
	}
	return dfs(node->left, voyage) && dfs(node->right, voyage);
}