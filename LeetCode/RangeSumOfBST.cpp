#include "stdafx.h"
#include "RangeSumOfBST.h"

void rangeSumBSTHelper(TreeNode* node, int L, int R, int &ans) {
	if (!node) return;

	if (L <= node->val && R >= node->val) ans += node->val;

	if (L < node->val) rangeSumBSTHelper(node->left, L, R, ans);
	if (R > node->val) rangeSumBSTHelper(node->right, L, R, ans);

	return;
}

int Solution::rangeSumBST(TreeNode* root, int L, int R) {
	int ans = 0;
	rangeSumBSTHelper(root, L, R, ans);
	return ans;
}