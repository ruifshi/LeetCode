#pragma once

#include <vector>
#include <unordered_map>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
  unordered_map<int, int> hmap;

public:
  TreeNode* helper(int left, int right, int postIdx, vector<int>& inorder, vector<int>& postorder);
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
};