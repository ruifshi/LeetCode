#include "stdafx.h"
#include "MaximumWidthOfBinaryTree.h"

#include <queue>

using namespace std;

int Solution::widthOfBinaryTree(TreeNode* root) {
  if (!root) return 0;

  long maxW = 0;
  // current node to column index
  queue<pair<TreeNode*, int>> q;

  q.push({ root, 0 });

  // do level order traversal and keep track of right most
  // col indx - left most col idx
  while (!q.empty()) {
    int q_sz = q.size();
    long colBegin = q.front().second;
    long col = q.front().second;

    for (int i = 0; i < q_sz; i++) {
      TreeNode* node = q.front().first;
      col = q.front().second;
      q.pop();

      if (node->left) {
        q.push({ node->left, col * 2 });
      }

      if (node->right) {
        q.push({ node->right, col * 2 + 1});
      }
    }

    // +1 since 0 index
    maxW = max(maxW, col - colBegin + 1);
  }

  return maxW;
}

/*
class Solution {
    private Integer maxWidth = 0;
    private HashMap<Integer, Integer> firstColIndexTable;

    protected void DFS(TreeNode node, Integer depth, Integer colIndex) {
        if (node == null)
            return;
        // initialize the value, for the first seen colIndex per level
        if (!firstColIndexTable.containsKey(depth)) {
            firstColIndexTable.put(depth, colIndex);
        }
        Integer firstColIndex = firstColIndexTable.get(depth);

        maxWidth = Math.max(this.maxWidth, colIndex - firstColIndex + 1);

        // Preorder DFS. Note: it is important to put the priority on the left child
        DFS(node.left, depth + 1, 2 * colIndex);
        DFS(node.right, depth + 1, 2 * colIndex + 1);
    }

    public int widthOfBinaryTree(TreeNode root) {
        // table contains the first col_index for each level
        this.firstColIndexTable = new HashMap<Integer, Integer>();

        // start from depth = 0, and colIndex = 0
        DFS(root, 0, 0);

        return this.maxWidth;
    }
}
*/