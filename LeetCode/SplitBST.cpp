#include "stdafx.h"
#include "SplitBST.h"

// returns a left right split where [0] = left (equal or smaller) and [1] = right (larger)
vector<TreeNode*> Solution::splitBST(TreeNode* root, int V) {

  if (!root) {
    return { NULL,NULL };
  }

  //case 1: we found V
  // everything to our right is one tree
  // and everything including us and to our left is a different tree
  if (root->val == V) {

    TreeNode *temp = root->right;
    root->right = NULL;
    return { root,temp };
  }

  //case2: root's value is smaller than V
  if (root->val < V) {

    //there is a right to root
    if (root->right) {

      //call recursively on the right
      vector<TreeNode*> res = splitBST(root->right, V);

      //the result we received has two subtrees, one containing V and smaller nodes
      // other containing larger than V
      // since we went to the right this root should be part the smaller tree (that includes V).
      root->right = res[0];
      return { root,res[1] };

    }
    else {
      //V is not to be found. we return root (as it is smaller than V) and NULL
      return { root,NULL };
    }
  }

  //case3 : symetric to case 2
  if (root->left) {
    vector<TreeNode*> res = splitBST(root->left, V);
    root->left = res[1];
    return { res[0],root };
  }

  return { NULL,root };
}  