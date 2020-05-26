#include "stdafx.h"
#include "MaximumDifferenceBetweenNodeAndAncestor.h"

#include <algorithm>

void maxAncestorDiffHelper(TreeNode* node, int start, int end, int &ans) {
	if (!node)
		return;

	if (node->val < start)
		start = node->val;
	if (node->val > end)
		end = node->val;

	ans = std::max(ans, end - start);

	maxAncestorDiffHelper(node->left, start, end, ans);
	maxAncestorDiffHelper(node->right, start, end, ans);
}

int Solution::maxAncestorDiff(TreeNode* root) {
	int ans = 0;
	if (!root) return ans;
	maxAncestorDiffHelper(root, root->val, root->val, ans);
	return ans;
}