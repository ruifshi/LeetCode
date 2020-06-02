#include "stdafx.h"
#include "ConvertBinarySearchTreeToSortedDoublyLinkedList.h"

// in order traversal
void treeToDoublyListHelper(Node* node, Node*& prev, Node*& head) {
  if (node->left) 
    treeToDoublyListHelper(node->left, prev, head);
  // find the head of the list which the is left most node
  if (!prev)
    head = node;
  else {
    // connect previous node and current node
    prev->right = node;
    node->left = prev;
  }
  prev = node;
  if (node->right) 
    treeToDoublyListHelper(node->right, prev, head);

}

Node* Solution::treeToDoublyList(Node* root) {
  if (!root) return nullptr;
  Node* head = nullptr;
  Node* prev = nullptr;
  treeToDoublyListHelper(root, prev, head);

  // link the head with the last node
  prev->right = head;
  head->left = prev;
  return head;
}