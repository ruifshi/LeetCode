#include "stdafx.h"
#include "InorderSuccessorInBST.h"

// O(n), depth of the tree
TreeNode* Solution::inorderSuccessor(TreeNode* root, TreeNode* p) {
	if(root == NULL || p == NULL) {
		return NULL;
	}

	TreeNode* curr = p->right;

	// If right child exists, then it's the minimum value to the right
	if(curr != NULL) {
		while(curr->left != NULL) {
			curr = curr->left;
		}

		return curr;
	}

	// If right child doesn't exist, then it's an ancestor
	curr = NULL;

	while(root != NULL) {
		if(p->val < root->val) {
			curr = root;
			root = root->left;
		}
        else if (p->val > root->val){
            root = root->right;
        }
        else {
            break;
        }
	}

	return curr;
}