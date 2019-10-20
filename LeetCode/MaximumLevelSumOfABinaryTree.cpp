#include "stdafx.h"
#include "MaximumLevelSumOfABinaryTree.h"

#include <queue>
#include <vector>
#include <map>

using namespace std;

//O(n) number of nodes
int Solution::maxLevelSum(TreeNode* root) {
	queue<TreeNode*> q;
	int ans = 0, level = 0;
	map<int, int, greater<int>> mp;

	if (root == NULL) return ans;

	q.push(root);

	while (!q.empty()) {
		int q_size = q.size();
		int sum = 0;
		level++;
		for (int i = 0; i < q_size; i++) {
			TreeNode* node = q.front();
			q.pop();

			sum += node->val;

			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}

		mp[sum] = level;
	}

	return mp.begin()->second;
}