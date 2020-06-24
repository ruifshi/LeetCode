#include "stdafx.h"
#include "ImplementMagicDictionary.h"

//  unordered_set<string> dictSet; 

/** Initialize your data structure here. */
MagicDictionary::MagicDictionary() {

}

/** Build a dictionary through a list of words */
void MagicDictionary::buildDict(vector<string> dict) {
  for (int i = 0; i < dict.size(); i++) {
    dictSet.insert(dict[i]);
  }
}

/** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
bool MagicDictionary::search(string word) {
  for (int i = 0; i < word.size(); i++) {
    char c = word[i];
    for (int j = 0; j < 26; j++) {
      if (c == j + 'a') continue;
      word[i] = j + 'a';
      if (dictSet.count(word)) return true;
    }
    word[i] = c;
  }
  return false;
}