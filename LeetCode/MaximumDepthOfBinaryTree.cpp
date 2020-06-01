#include "stdafx.h"
#include "MaximumDepthOfBinaryTree.h"
#include <algorithm>

int maxDepthHelper(TreeNode* node) {
	if (node == NULL) {
		return 0;
	}

	return std::max(maxDepthHelper(node->left) + 1, maxDepthHelper(node->right) + 1);
}

int Solution::maxDepth(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	return maxDepthHelper(root);
}