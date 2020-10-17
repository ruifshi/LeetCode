#include "stdafx.h"
#include "WordPattern.h"

#include <unordered_map>

bool Solution::wordPattern(string pattern, string s) {
  int i = 0, j = 0, len = pattern.size(), n = s.size();
  unordered_map<char, string> map1;
  unordered_map<string, char> map2;
  string word = "";

  while (j < len)
  {
    if (i > n) return false;//there are letters in pattern but str has no word
    while (s[i] != ' ' && s[i] != '\0')//get the word
      word += s[i++];

    if (map1.find(pattern[j]) != map1.end() && map1[pattern[j]] != word)
      return false;
    if (map2.find(word) != map2.end() && map2[word] != pattern[j])
      return false;

    map1[pattern[j]] = word;
    map2[word] = pattern[j];
    ++j, ++i;
    word = "";
  }
  if (i <= n)//there are no letters in pattern, but str still has word
    return false;

  return true;
}