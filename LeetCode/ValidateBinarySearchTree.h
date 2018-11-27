#include "stdafx.h"
#include "limits.h"

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isValidBST(TreeNode* root);
	bool isValidBSTHelper(TreeNode* node, long min, long max);
};