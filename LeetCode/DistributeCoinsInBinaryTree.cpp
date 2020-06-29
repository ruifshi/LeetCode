#include "stdafx.h"
#include "DistributeCoinsInBinaryTree.h"

#include <limits>

// returns excess number of coins in the subtree or below this node
int dfs(TreeNode* node, int &moves) {
  if (!node) return 0;
  int left = dfs(node->left, moves);
  int right = dfs(node->right, moves);

  // if a node needs a coin, then it's a negative value but a positive move
  moves += abs(left) + abs(right);
  return node->val + left + right - 1; // keep 1 coin at this node
}

/*
https://leetcode.com/problems/distribute-coins-in-binary-tree/discuss/221939/C%2B%2B-with-picture-post-order-traversal

Thinking about this problem this way helped me: the algorithm traverses the tree bottom up, 
and while traversing the tree upwards as we go we try to maintain the property that the nodes 
traversed until now have only one coin, if a particular coin has excess coins we simply pass 
the "remaining balance" upwards, and suppose a node has no coins then we allot it one coin and 
pass the "negative balance" upwards(which really means passing coins downwards from excess nodes). 
Think of the positive flows as passing coins from excess nodes to deficient nodes and the the 
negative flows as positive flows in the "reverse" direction, the number of coins would balance 
out because they are equal to the number of nodes(the "credit" and "debt" cancel out).
*/
int Solution::distributeCoins(TreeNode* root) {
  int moves = 0;
  dfs(root, moves);
  return moves;
}