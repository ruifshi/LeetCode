#include "stdafx.h"
#include "VerticalOrderTraversalOfABinaryTree.h"

#include <algorithm>

// Store the locations of the nodes as you traverse and then print in the order
// of the x value (i.e. vertical columns)
vector<vector<int>> Solution::verticalTraversal(TreeNode* root) {
	// Create a map and store vertical oder in map using 
	// function dfs() 
	map < int, vector<int> > m;
	int hd = 0;
	vector <vector<int>> ans;

	dfs(root, hd, m);

	// Traverse the map and print nodes at every horigontal 
	// distance (hd) 
	map< int, vector<int> > ::iterator it;
	for (it = m.begin(); it != m.end(); it++)
	{
		ans.push_back(it->second);
	}

	return ans;
}

void Solution::dfs(TreeNode* root, int hd, map<int, vector<int>> &m) {
	// Base case 
	if (root == NULL)
		return;

	// Store current node in map 'm' 
	m[hd].push_back(root->val);

	// Store nodes in left subtree 
	dfs(root->left, hd - 1, m);

	// Store nodes in right subtree 
	dfs(root->right, hd + 1, m);
}