#include "stdafx.h"
#include "DiameterOfBinaryTree.h"

#include <algorithm>

int diameterOfBinaryTreeHelper(TreeNode* root, int &ans) {
	if (!root) return 0;

	int left = diameterOfBinaryTreeHelper(root->left, ans);
	int right = diameterOfBinaryTreeHelper(root->right, ans);

	ans = std::max(ans, left + right + 1); // + 1 for current node

	return std::max(left, right) + 1;
}

int Solution::diameterOfBinaryTree(TreeNode* root) {
	if (!root) return 0;

	int ans = 0;

	diameterOfBinaryTreeHelper(root, ans);

	return ans - 1; // edges not paths E=V-1
}