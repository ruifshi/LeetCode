#include "stdafx.h"
#include "RepeatedDNASequences.h"

#include <unordered_map>

vector<string> Solution::findRepeatedDnaSequences(string s) {
  vector<string> res;
  unordered_map<string, int> mymap;
  for (int i = 0; i + 9 < s.length(); i++) {
    string sub = s.substr(i, 10);
    mymap[sub]++;
  }
  for (auto val : mymap) {
    if (val.second > 1) {
      res.push_back(val.first);
    }
  }
  return res;
}