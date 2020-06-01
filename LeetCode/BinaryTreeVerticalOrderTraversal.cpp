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

/*
/// DFS, O(n) Sapce and O(nlgn) Time, a little bit slower but easier to write.
class Solution {
    map<int, map<int, vector<int>>> table;
    void dfs(TreeNode * root, int i, int j)
    {
        if (root == nullptr)
            return;
        table[j][i].push_back(root->val);
        dfs(root->left, i + 1, j - 1);
        dfs(root->right, i + 1, j + 1);
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> result;
        for (const auto & col : table)
        {
            result.emplace_back();
            for (const auto & elem : col.second)
            {
                const auto & vec = elem.second;
                copy(vec.begin(), vec.end(), back_inserter(result.back()));
            }
        }
        return result;
    }
};
*/