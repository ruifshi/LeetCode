#include "stdafx.h"
#include "AllNodesDistanceKinBinaryTree.h"

// A tree is a directed acyclic graph. We can do a graph search from the target.
// However, a tree can only traverse down so we need to save the parent nodes of
// each child and also do a search from the parent.
vector<int> Solution::distanceK(TreeNode* root, TreeNode* target, int K) {
	if (!root) return {};

	findParent(root);
	dfs(target, K);
	return ans;
}

void Solution::findParent(TreeNode* node) {
	if (!node) return;
	if (node->left) {
		parent[node->left] = node;
		findParent(node->left);
	}
	if (node->right) {
		parent[node->right] = node;
		findParent(node->right);
	}
}

void Solution::dfs(TreeNode* node, int K) {
	if (visit.find(node) != visit.end())
		return;
	visit.insert(node);
	if (K == 0) {
		ans.push_back(node->val);
		return;
	}
	if (node->left) {
		dfs(node->left, K - 1);
	}
	if (node->right) {
		dfs(node->right, K - 1);
	}
	TreeNode* p = parent[node];
	if (p)
		dfs(p, K - 1);
}