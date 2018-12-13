#include "stdafx.h"
#include "BinarySearchTreeIterator.h"

BSTIterator::BSTIterator(TreeNode *root) {
	TreeNode *n = root;
	inOrderTrav(root);

	return;
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
	return !q.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
	if (!q.empty()) {
		int val = q.front()->val;
		q.pop();
		return val;
	}
	else {
		return NULL;
	}
}

// basically just print the values in order
void BSTIterator::inOrderTrav(TreeNode *root) {
	if (root == NULL) {
		return;
	}

	inOrderTrav(root->left);
	
	q.push(root);

	inOrderTrav(root->right);

	return;
}