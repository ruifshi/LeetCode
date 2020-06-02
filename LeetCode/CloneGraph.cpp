#include "stdafx.h"
#include "CloneGraph.h"

#include <queue>
#include <unordered_map>

Node* Solution::cloneGraph(Node* node) {
  unordered_map<Node*, Node*> copies; // hashmap to keep track of which copy goes where

  if (!node) {
    return NULL;
  }
  Node* copy = new Node(node->val, {});
  copies[node] = copy;
  queue<Node*> todo;
  todo.push(node);
  while (!todo.empty()) {
    Node* cur = todo.front();
    todo.pop();
    for (Node* neighbor : cur->neighbors) {
      if (copies.find(neighbor) == copies.end()) {
        copies[neighbor] = new Node(neighbor->val, {});
        todo.push(neighbor);
      }
      copies[cur]->neighbors.push_back(copies[neighbor]);
    }
  }
  return copy;
}

/*
unordered_map<Node*, Node*> copies;

Node* cloneGraph(Node* node) {
  if (!node) {
    return NULL;
  }
  if (copies.find(node) == copies.end()) {
    copies[node] = new Node(node->val, {});
    for (Node* neighbor : node->neighbors) {
      copies[node]->neighbors.push_back(cloneGraph(neighbor));
    }
  }
  return copies[node];
}
*/