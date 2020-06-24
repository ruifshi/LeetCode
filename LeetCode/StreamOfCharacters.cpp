#include "stdafx.h"
#include "StreamOfCharacters.h"

// keeps track of all possible positions from previous query
//vector<TrieNode*> paths;

StreamChecker::StreamChecker(vector<string>& words) {
  root = new TrieNode();

  for (int i = 0; i < words.size(); i++) {
    TrieNode* node = root;
    for (int j = 0; j < words[i].size(); j++) {
      if (!node->next[words[i][j]]) {
        node->next[words[i][j]] = new TrieNode();
      }

      node = node->next[words[i][j]];
    }

    node->end = true;
  }
}

bool StreamChecker::query(char letter) {
  bool out = false;

  vector<TrieNode*> cur_path;
  paths.push_back(root);  // always need to start from top if prev had no results

  for (int i = 0; i < paths.size(); i++) {
    TrieNode *node = paths[i]->next[letter];
    if (node) {
      if (node->end) {
        out = true;
      }
      cur_path.push_back(node);
    }
  }

  paths = cur_path;

  return out;
}