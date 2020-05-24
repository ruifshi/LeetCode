#include "stdafx.h"
#include "BinaryTreeVerticalOrderTraversal.h"

#include <map>
#include <queue>

vector<vector<int>> Solution::verticalOrder(TreeNode* root) {
	vector<vector<int>> ans;

	if (!root) return ans;

	map<int, vector<int>> levels;  // map for nodes at each level
	queue<pair<int, TreeNode*>> q;	// int keep track of the level

	q.push(make_pair(0, root));

	while (!q.empty()) {
		TreeNode* Node = q.front().second;
		int level = q.front().first;
		q.pop();

		if (Node->left) q.push(make_pair(level - 1, Node->left));
		if (Node->right) q.push(make_pair(level + 1, Node->right));

		levels[level].push_back(Node->val);
	}

	for (auto x : levels) ans.push_back(x.second);

	return ans;
}