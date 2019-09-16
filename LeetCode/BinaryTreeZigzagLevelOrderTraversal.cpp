#include "stdafx.h"
#include "BinaryTreeZigzagLevelOrderTraversal.h"

#include <queue>
#include <algorithm>

vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* root) {
	queue<TreeNode*> q;
	vector<vector<int>> ans;

	if (root == NULL) return ans;

	q.push(root);

	bool rev = false;

	while (!q.empty()) {
		vector<int> level;
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			TreeNode* node = q.front();
			q.pop();

			level.push_back(node->val);

			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}

		if (rev) reverse(level.begin(), level.end());
		ans.push_back(level);
		rev = !rev;
	}

	return ans;
}