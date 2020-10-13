#include "stdafx.h"
#include "UncommonWordsFromTwoSentences.h"

#include <unordered_map>

vector<string> Solution::uncommonFromSentences(string A, string B) {
  unordered_map<string, int> count;
  vector<string> singles;

  int start = 0, end = 0;
  while ((end = A.find(" ", start)) != string::npos) {
    count[A.substr(start, end - start)]++;
    start = end+1;
  }
  count[A.substr(start, A.size() - start)]++;

  start = 0, end = 0;
  while ((end = B.find(" ", start)) != string::npos) {
    count[B.substr(start, end - start)]++;
    start = end+1;
  }
  count[B.substr(start, B.size() - start)]++;

  for (auto &s : count) {
    if (s.second == 1) {
      singles.push_back(s.first);
    }
  }

  return singles;
}