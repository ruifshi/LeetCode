#include "stdafx.h"
#include "FlattenAMultilevelDoublyLinkedList.h"

#include <stack>

using namespace std;

/*
we could consider the child pointer as the left pointer in binary tree which 
points to the left sub-tree (sublist). And similarly, the next pointer can be 
considered as the right pointer in binary tree. Then if we traverse the tree in 
preorder DFS, it would generate the same visiting sequence as the flatten operation 
in our problem.
*/
Node* Solution::flatten(Node* head) {
  if (!head) return head;

  Node preHead;
  Node* cur, *prev = &preHead;
  stack<Node*> stk;

  stk.push(head);

  // use a stk to keep track of which nodes to connect
  // always connect child nodes first. Use prev to keep
  // track of the previously connected nodes
  while (!stk.empty()) {
    cur = stk.top();
    stk.pop();
    prev->next = cur;
    cur->prev = prev;

    if (cur->next) stk.push(cur->next);
    if (cur->child) {
      stk.push(cur->child);
      cur->child = nullptr;
    }

    prev = cur;
  }

  // need to remove the first connection back to the preHead
  preHead.next->prev = nullptr;
  return preHead.next;
}