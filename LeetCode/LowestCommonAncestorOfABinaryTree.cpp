#include "stdafx.h"
#include "LowestCommonAncestorOfABinaryTree.h"

struct LCA{
	int target_num;
	TreeNode* LCA;
};

LCA lowestCommonAncestorHelper(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!root) return { 0, nullptr };

	LCA left = lowestCommonAncestorHelper(root->left, p, q);
	LCA right = lowestCommonAncestorHelper(root->right, p, q);

	if (left.target_num == 2) return left;
	if (right.target_num == 2) return right;

	int target_num = left.target_num + right.target_num;
	if (root == p || root == q) {
		target_num++;
	}

	TreeNode* node = nullptr;
	if (target_num == 2) node = root;

	return { target_num, node };
}

TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	return lowestCommonAncestorHelper(root, p, q).LCA;
}