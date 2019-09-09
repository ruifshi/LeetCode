#include "stdafx.h"
#include "MaximumDepthOfBinaryTree.h"
#include <algorithm>

int maxDepthHelper(TreeNode* node, int ans) {
	if (node == NULL) {
		return ans;
	}

	ans++;

	return std::max(maxDepthHelper(node->left, ans), maxDepthHelper(node->right, ans));
}

int Solution::maxDepth(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	int ans = 0;
	return maxDepthHelper(root, ans);
}