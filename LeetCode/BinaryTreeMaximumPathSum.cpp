#include "stdafx.h"
#include "BinaryTreeMaximumPathSum.h"

#include <algorithm>

int Solution::maxPathSum(TreeNode* root) {
	int sum = INT_MIN;
	help(root, sum);
	return sum;
}

/*** return the max-value-ended-at-root-node ***/
int Solution::help(TreeNode* root, int &sum) {
	if (!root)   
		return 0;
	int left = std::max(0, help(root->left, sum));
	int right = std::max(0, help(root->right, sum));
	
	// choose between current path or the cycle with current node and left and right
	sum = std::max(sum, left + right + root->val);

	// current path
	return std::max(left, right) + root->val;
}