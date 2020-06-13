#include "stdafx.h"
#include "PopulatingNextRightPointersInEachNodeII.h"

#include <queue>

using namespace std;

Node* Solution::connect(Node* root) {
  if (!root) return nullptr;

  queue<Node*> q;

  q.push(root);

  // do level order traversal and connect to next node
  // in the queue
  while (!q.empty()) {
    int qsize = q.size();

    for (int i = 0; i < qsize; i++) {
      Node* node = q.front();
      q.pop();

      // last node should connect to null
      if (i < qsize - 1) {
        node->next = q.front();
      }

      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
  }

  return root;
}

/*
class Solution {

    Node prev, leftmost;

    public void processChild(Node childNode) {

        if (childNode != null) {

            // If the "prev" pointer is alread set i.e. if we
            // already found atleast one node on the next level,
            // setup its next pointer
            if (this.prev != null) {
                this.prev.next = childNode;

            } else {

                // Else it means this child node is the first node
                // we have encountered on the next level, so, we
                // set the leftmost pointer
                this.leftmost = childNode;
            }

            this.prev = childNode;
        }
    }

    public Node connect(Node root) {

        if (root == null) {
            return root;
        }

        // The root node is the only node on the first level
        // and hence its the leftmost node for that level
        this.leftmost = root;

        // Variable to keep track of leading node on the "current" level
        Node curr = leftmost;

        // We have no idea about the structure of the tree,
        // so, we keep going until we do find the last level.
        // the nodes on the last level won't have any children
        while (this.leftmost != null) {

            // "prev" tracks the latest node on the "next" level
            // while "curr" tracks the latest node on the current
            // level.
            this.prev = null;
            curr = this.leftmost;

            // We reset this so that we can re-assign it to the leftmost
            // node of the next level. Also, if there isn't one, this
            // would help break us out of the outermost loop.
            this.leftmost = null;

            // Iterate on the nodes in the current level using
            // the next pointers already established.
            while (curr != null) {

                // Process both the children and update the prev
                // and leftmost pointers as necessary.
                this.processChild(curr.left);
                this.processChild(curr.right);

                // Move onto the next node.
                curr = curr.next;
            }
        }

        return root ;
    }
}
*/