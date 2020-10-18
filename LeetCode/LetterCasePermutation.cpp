#include "stdafx.h"
#include "LetterCasePermutation.h"

void dfs(int index, string& str, vector<string>& ans, string& pattern) {
  if (index > str.size()) {
    ans.push_back(pattern);
    return;
  }

  // lower case to upper case
  if (str[index] >= 'a' && str[index] <= 'z') {
    char ch = str[index];
    ch = ch - 32;
    string st = pattern + ch;
    dfs(index + 1, str, ans, st);
    //  pattern.substring(0, pattern.length()-1);
  }

  // upper case to lower
  if (str[index] >= 'A' && str[index] <= 'Z') {
    char ch = str[index];
    ch = ch + 32;
    string st = pattern + ch;
    dfs(index + 1, str, ans, st);
    //  pattern.substring(0, pattern.length()-1);
  }

  //number
  string st = pattern + str[index];
  dfs(index + 1, str, ans, st);
  // pattern.substring(0, pattern.length()-1);
}

vector<string> Solution::letterCasePermutation(string S) {
  vector<string> ans;
  string st = "";

  dfs(0, S, ans, st);
  return ans;
}