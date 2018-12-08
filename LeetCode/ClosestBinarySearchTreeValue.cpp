#include "stdafx.h"
#include "ClosestBinarySearchTreeValue.h"
#include <cmath>

int Solution::closestValue(TreeNode* root, double target) {
	/*
    int ans = root->val;
    while (root) {
        if (abs(ans - target) >= abs(root->val - target))
            ans = root->val;
        root = target < root->val ? root->left : root->right;
    }
    return closest;
	*/

	double ans = root->val;
	closestValueHelper(root, target, ans);
	return ans;
}

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