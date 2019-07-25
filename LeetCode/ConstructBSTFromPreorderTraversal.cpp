#include "stdafx.h"
#include "ConstructBSTFromPreorderTraversal.h"

TreeNode* Solution::bstFromPreorder(vector<int>& preorder) {
	int indx = 0;
	return helper(preorder, indx, INT_MIN, INT_MAX);
}

TreeNode* Solution::helper(vector<int> &preorder, int &indx, int lower, int upper) {
	// if all elements from preorder are used
	// then the tree is constructed
	if (indx == preorder.size()) {
		return NULL;
	}

	int val = preorder[indx];

	// if the current element 
	// couldn't be placed here to meet BST requirements
	if (val < lower || val > upper) {
		return NULL;
	}

	// place the current element
	// and recursively construct subtrees
	indx++;
	TreeNode *root = new TreeNode(val);
	root->left = helper(preorder, indx, lower, val);
	root->right = helper(preorder, indx, val, upper);

	return root;
}