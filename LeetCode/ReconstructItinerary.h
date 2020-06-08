#pragma once

#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
private:
  unordered_map<string, multiset<string>> targets;
  vector<string> route;
public:
  vector<string> findItinerary(vector<pair<string, string>> &tickets);
  void visit(string airport);
};