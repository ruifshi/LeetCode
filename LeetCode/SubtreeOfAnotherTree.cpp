#include "stdafx.h"
#include "SubtreeOfAnotherTree.h"

// You can do preorder traversal and save the nodes as a string
// then use str.find to see if the subtree exits
bool Solution::isSubtree(TreeNode* s, TreeNode* t) {
	if (!s) return false;
	return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}

// this checks every node to see if they are equal
bool Solution::isSameTree(TreeNode* p, TreeNode* q) {
	if (p == NULL && q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	if (p->val == q->val)
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	else
		return false;
}