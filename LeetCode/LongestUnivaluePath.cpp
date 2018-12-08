#include "stdafx.h"
#include "LongestUnivaluePath.h"
#include "math.h"

#include <algorithm>
#include <vector>

using namespace std;

int Solution::helper(TreeNode *node, int *solution) {
	if(node == NULL) {
		return 0;
	}

	int left = helper(node->left, solution);
	int right = helper(node->right, solution);

	int arrowLeft = 0;
	int arrowRight = 0;

	if(node->left != NULL && node->left->val == node->val) {
		arrowLeft += left + 1;
	}

	if(node->right != NULL && node->right->val == node->val) {
		arrowRight += right + 1;
	}

	*solution = max(*solution, arrowLeft + arrowRight);
	return max(arrowLeft, arrowRight);
}

int Solution::longestUnivaluePath(TreeNode* root) {
	int solution = 0;

	if(root == NULL) {
		return 0;
	}

	helper(root, &solution);

	return solution;
}