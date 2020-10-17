#include "stdafx.h"
#include "HouseRobberIII.h"

#include <unordered_map>
#include <algorithm>

using namespace std;

/*
In step I, we only considered the aspect of "optimal substructure", but think little about the 
possibilities of overlapping of the subproblems. For example, to obtain rob(root), we need rob(root.left), 
rob(root.right), rob(root.left.left), rob(root.left.right), rob(root.right.left), rob(root.right.right); 
but to get rob(root.left), we also need rob(root.left.left), rob(root.left.right), similarly for rob(root.right). 
The naive solution above computed these subproblems repeatedly, which resulted in bad time performance. 
Now if you recall the two conditions for dynamic programming (DP): "optimal substructure" + "overlapping of subproblems", 
we actually have a DP problem. A naive way to implement DP here is to use a hash map to record the results for visited subtrees.
*/
int helper(TreeNode* root, unordered_map<TreeNode*, int> mp) {
  if (!root) return 0;
  if (mp.find(root) != mp.end()) return mp[root];

  int val = 0;

  //robbing left
  if (root->left != nullptr) {
    val += helper(root->left->left, mp) + helper(root->left->right, mp);
  }

  //robbing right
  if (root->right != nullptr) {
    val += helper(root->right->left, mp) + helper(root->right->right, mp);
  }

  // find if robbing this node is max or not
  val = max(val + root->val, helper(root->left, mp) + helper(root->right, mp));
  mp[root] = val;

  return val;
}

int Solution::rob(TreeNode* root) {
  unordered_map<TreeNode*, int> mp; //node to max val underneath
  return helper(root, mp);
}

/*
In step I, we defined our problem as rob(root), which will yield the maximum amount of money that can be robbed of the binary tree rooted at root. 
This leads to the DP problem summarized in step II.

Now let's take one step back and ask why we have overlapping subproblems. If you trace all the way back to the beginning, 
you'll find the answer lies in the way how we have defined rob(root). As I mentioned, for each tree root, there are two scenarios: 
it is robbed or is not. rob(root) does not distinguish between these two cases, so "information is lost as the recursion goes deeper and deeper", 
which results in repeated subproblems.

If we were able to maintain the information about the two scenarios for each tree root, let's see how it plays out. 
Redefine rob(root) as a new function which will return an array of two elements, the first element of which denotes 
the maximum amount of money that can be robbed if root is not robbed, while the second element signifies the maximum amount of money robbed if it is robbed.

Let's relate rob(root) to rob(root.left) and rob(root.right)..., etc. For the 1st element of rob(root), 
we only need to sum up the larger elements of rob(root.left) and rob(root.right), respectively, since root is not robbed and we are free to rob its left and right subtrees. 
For the 2nd element of rob(root), however, we only need to add up the 1st elements of rob(root.left) and rob(root.right), respectively, 
plus the value robbed from root itself, since in this case it's guaranteed that we cannot rob the nodes of root.left and root.right.
*/
/*
vector<int> helper(TreeNode* root) {
  if (!root) return {0,0};

  vector<int> left = helper(root->left);
  vector<int> right = helper(root->right);
  vector<int> res = {0,0};

  res[0] = max(left[0], left[1]) + max(right[0], right[1]);
  res[1] = root->val + left[0] + right[0];

  return res;
}

int rob(TreeNode* root) {
    vector<int> res = helper(root);
    return max(res[0], res[1]);
}
*/