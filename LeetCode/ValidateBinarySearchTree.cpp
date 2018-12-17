#include "stdafx.h"
#include "ValidateBinarySearchTree.h"

//O(n), all the nodes
bool Solution::isValidBST(TreeNode* root) {
	return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}

bool Solution::isValidBSTHelper(TreeNode* node, long min, long max) {
	if(node == NULL) {
		return true;
	}

	if(node->val <= min || node->val >= max) {
		return false;
	}

	return isValidBSTHelper(node->left, min, node->val) && isValidBSTHelper(node->right, node->val, max);
}