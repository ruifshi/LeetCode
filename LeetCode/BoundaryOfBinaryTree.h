#include "stdafx.h"

#include <vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> boundaryOfBinaryTree(TreeNode* root);
	void getLeft(TreeNode* curr, vector<int>&lefts);
	void getLeaves(TreeNode * curr, vector<int>&leaves);
	void getRight(TreeNode*curr, vector<int>&rights);
};