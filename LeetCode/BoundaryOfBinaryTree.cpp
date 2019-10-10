#include "stdafx.h"
#include "BoundaryOfBinaryTree.h"

void Solution::getLeft(TreeNode* curr, vector<int>&lefts)
{
	if (!curr || (curr->left == NULL && curr->right == NULL)) return;
	lefts.push_back(curr->val);
	if (curr->left)
		getLeft(curr->left, lefts);
	else
		getLeft(curr->right, lefts);
}

void Solution::getLeaves(TreeNode * curr, vector<int>&leaves)
{
	if (!curr) return;
	if (curr->left == NULL && curr->right == NULL) leaves.push_back(curr->val);
	getLeaves(curr->left, leaves);
	getLeaves(curr->right, leaves);
}

void Solution::getRight(TreeNode*curr, vector<int>&rights)
{
	if (!curr || (curr->left == NULL && curr->right == NULL)) return;
	rights.push_back(curr->val);
	if (curr->right) 
		getRight(curr->right, rights);
	else 
		getRight(curr->left, rights);
}

vector<int> Solution::boundaryOfBinaryTree(TreeNode* root) {
	vector<int>res;
	if (!root) return res;
	res.push_back(root->val);
	vector<int>lefts, leaves, rights;

	getLeft(root->left, lefts);
	getLeaves(root->left, leaves);
	getLeaves(root->right, leaves);
	getRight(root->right, rights);
	reverse(rights.begin(), rights.end());

	for (auto l : lefts) res.push_back(l);
	for (auto leave : leaves) res.push_back(leave);
	for (auto r : rights) res.push_back(r);

	return res;
}