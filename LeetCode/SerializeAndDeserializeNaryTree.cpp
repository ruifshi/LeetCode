#include "stdafx.h"
#include "SerializeAndDeserializeNaryTree.h"

int GetNumber(const string &str, int &index) {
  int sum = 0;
  while (index < str.size() && isdigit(str[index])) {
    sum = 10 * sum + (str[index] - '0');
    ++index;
  }
  return sum;
}

void serializeHelper(Node* node, string &str) {
  if (node == nullptr) {
    str += ';';
    return;
  }
  str += to_string(node->val);
  if (node->children.size() == 0) {
    str += ';';
    return;
  }
  str += ',';
  str += to_string(node->children.size());
  str += ',';
  for (int i = 0; i < node->children.size(); ++i) {
    serializeHelper(node->children[i], str);
  }
  return;
}

// Encodes a tree to a single string.
string Codec::serialize(Node* root) {
  string str;
  serializeHelper(root, str);
  return str;
}

Node* deserializeHelper(const string &data, int &index) {
  if (index >= data.size())
    return nullptr;
  if (data[index] == ';') {
    ++index;
    return nullptr;
  }
  Node * node = new Node();
  node->val = GetNumber(data, index);
  if (data[index] == ';') {
    ++index;
    return node;
  }

  ++index;
  int num_children = GetNumber(data, index);

  ++index;
  node->children.reserve(num_children);
  for (int i = 0; i < num_children; ++i) {
    node->children.push_back(deserializeHelper(data, index));
  }
  return node;
}

// Decodes your encoded data to tree.
Node* Codec::deserialize(string data) {
  int index = 0;
  return deserializeHelper(data, index);
}