#include "stdafx.h"
#include "AllPossibleFullBinaryTrees.h"

/*
With a given N, the root consumes 1, and the left subtree consumes i and the right subtree consumes N - 1 - i. 
Traverse all the i's by incrementing 2.
*/
vector<TreeNode*> Solution::allPossibleFBT(int N) {
  vector<TreeNode*> res;
  if (N == 1) {
    TreeNode* root = new TreeNode(0);
    res.push_back(root);
    return res;
  }
  for (int i = 1; i <= N - 2; i += 2) {
    vector<TreeNode*> l = allPossibleFBT(i);
    vector<TreeNode*> r = allPossibleFBT(N - 1 - i);
    for (int j = 0; j < l.size(); ++j) {
      for (int k = 0; k < r.size(); ++k) {
        TreeNode* root = new TreeNode(0);
        root->left = l[j];
        root->right = r[k];
        res.push_back(root);
      }
    }
  }
  return res;
}