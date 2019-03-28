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
	vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage);
	bool dfs(TreeNode* node, vector<int>& voyage);
	vector<int> res;
	int i = 0;
};