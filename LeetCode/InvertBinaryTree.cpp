#include "stdafx.h"
#include "InvertBinaryTree.h"

TreeNode* Solution::invertTree(TreeNode* root) {
	if (root == NULL) {
		return NULL;
	}
	TreeNode *right = invertTree(root->right);
	TreeNode *left = invertTree(root->left);
	root->left = right;
	root->right = left;
	return root;
}