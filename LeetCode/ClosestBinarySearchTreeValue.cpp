#include "stdafx.h"
#include "ClosestBinarySearchTreeValue.h"
#include <cmath>

// O(n), height of tree
int Solution::closestValue(TreeNode* root, double target) {
	/*
    int closest = root->val;
    while (root) {
        if (abs(closest - target) >= abs(root->val - target))
            closest = root->val;
        root = target < root->val ? root->left : root->right;
    }
    return closest;
	*/

	double ans = root->val;
	closestValueHelper(root, target, ans);
	return ans;
}

// loop through values and find the smallest abs difference between current
// node and target
void Solution::closestValueHelper(TreeNode* node, double target, double &ans) {
	if(node == NULL) {
		return;
	}

	if(abs(node->val - target) < abs(ans - target)) {
		ans = node->val;
	}

	if(node->val > target) {
		closestValueHelper(node->left, target, ans);
	}
	else {
		closestValueHelper(node->right, target, ans);
	}

	return;
}