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

  // if its less than 0, that means we should not connect current node with that branch, 
  // since it will decrease the value of the path that goes through current    
  // node anyway. In other words, if both branch have negative values, 
  // then it's better just not to connect current node with any of the branch (simply take current node's value alone).
  // This is like kadane's algorithm
	int left = std::max(0, help(root->left, sum));
	int right = std::max(0, help(root->right, sum));
	
	// choose between current path or the cycle with current node and left and right
	sum = std::max(sum, left + right + root->val);

	// current path
	return std::max(left, right) + root->val;
}