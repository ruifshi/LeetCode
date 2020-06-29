#include "stdafx.h"
#include "ImplementTrie.h"

/** Initialize your data structure here. */
Trie::Trie() {
  root = new TrieNode();
}

/** Inserts a word into the trie. */
void Trie::insert(string word) {
  TrieNode *node = root;

  for (char &c : word) {
    if (!node->next[c]) {
      node->next[c] = new TrieNode;
    }

    node = node->next[c];
  }

  node->end = true;
}

/** Returns if the word is in the trie. */
bool Trie::search(string word) {
  TrieNode *node = root;

  for (char &c : word) {
    if (node->next[c]) {
      node = node->next[c];
    }
    else {
      return false;
    }
  }

  return node->end;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool Trie::startsWith(string prefix) {
  TrieNode *node = root;

  for (char &c : prefix) {
    if (node->next[c]) {
      node = node->next[c];
    }
    else {
      return false;
    }
  }

  return true;
}