#include "stdafx.h"
#include "SortCharactersByFrequency.h"

#include <map>
#include <queue>

/*
    string frequencySort(string s) {
        int counts[256] = {0};
        for (char ch : s)
            ++counts[ch];
        sort(s.begin(), s.end(), [&](char a, char b) {
            return counts[a] > counts[b] || (counts[a] == counts[b] && a < b);
        });
        return s;
    }
*/

string Solution::frequencySort(string s) {
  map<char, int> freq;
  for (char c : s)
    freq[c]++;

  priority_queue<pair<int, char>> pqFreq;
  for (const auto& cf : freq) {
    pqFreq.push(make_pair(cf.second, cf.first));
  }

  string ret = "";
  while (!pqFreq.empty()) {
    auto val = pqFreq.top();
    ret += string(val.first, val.second);
    pqFreq.pop();
  }
  return ret;
}