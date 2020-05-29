#include "stdafx.h"
#include "LowestCommonAncestorOfDeepestLeaves.h"

#include <algorithm>

using namespace std;

int lcaDeepestLeavesHelper(TreeNode* node, TreeNode* &lca, int &deepest, int depth) {
	deepest = max(deepest, depth);
	if (!node) return depth;

	int left = lcaDeepestLeavesHelper(node->left, lca, deepest, depth + 1);
	int right = lcaDeepestLeavesHelper(node->right, lca, deepest, depth + 1);
	if (left == deepest && right == deepest) {
		lca = node;
	}
	return max(left, right);
}

TreeNode* Solution::lcaDeepestLeaves(TreeNode* root) {
	TreeNode* lca = root;
	int deepest = 0;
	int depth = 0;

	lcaDeepestLeavesHelper(root, lca, deepest, 0);

	return lca;
}