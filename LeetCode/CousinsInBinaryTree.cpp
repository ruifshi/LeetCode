#include "stdafx.h"
#include "CousinsInBinaryTree.h"

int level(TreeNode* root, int a, int lev) {
	if (root == NULL) {
		return 0;
	}

	if (root->val == a) {
		return lev;
	}

	int l = level(root->left, a, lev+1);

	// Return level if Node is present in left subtree 
	if (l != 0) {
		return l;
	}

	// Else search in right subtree 
	return level(root->right, a, lev + 1);
}

int isSibling(TreeNode* root, int a, int b) {
	if (root == NULL) {
		return 0;
	}

	// see if passed in values are both childs of current node
	if (((root->left != NULL) && (root->left->val == a)) && ((root->right != NULL) && (root->right->val == b))) {
		return 1;
	}

	if (((root->left != NULL) && (root->left->val == b)) && ((root->right != NULL) && (root->right->val == a))) {
		return 1;
	}

	//iterate
	return isSibling(root->left, a, b) || isSibling(root->right, a, b);
}

bool Solution::isCousins(TreeNode* root, int x, int y) {
	//1. The two Nodes should be on the same level in the binary tree. 
	//2. The two Nodes should not be siblings (means that they should 
	// not have the same parent Node). 
	if ((level(root, x, 1) == level(root, y, 1)) && !(isSibling(root, x, y))) {
		return true;
	}	
	else {
		return false;
	}
}