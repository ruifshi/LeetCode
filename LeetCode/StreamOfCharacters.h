#pragma once

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode {
  unordered_map<char, TrieNode*> next;
  bool end;

  TrieNode() { end = false; }
};

class StreamChecker {
private:
  TrieNode *root;
  vector<TrieNode*> paths;
public:
  StreamChecker(vector<string>& words);

  bool query(char letter);
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */