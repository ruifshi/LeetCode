#include "stdafx.h"

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* bstFromPreorder(vector<int>& preorder);
	TreeNode* helper(vector<int> &preorder, int &indx, int lower, int upper);
};