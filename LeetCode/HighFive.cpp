#include "stdafx.h"
#include "HighFive.h"

#include <map>
#include <queue>

vector<vector<int>> highFive(vector<vector<int>>& items) {
  if (items.size() == 0) return {};

  map<int, priority_queue<int, vector<int>, greater<int>>> mp;
  vector<vector<int>> out;

  for (auto &i : items) {
    mp[i[0]].push(i[1]);
    if (mp[i[0]].size() > 5) {
      mp[i[0]].pop();
    }
  }

  for (auto &i : mp) {
    vector<int> score;
    score.push_back(i.first);
    score.push_back(0);

    while (!i.second.empty()) {
      score.back() += i.second.top();
      i.second.pop();
    }
    score.back() /= 5;
    out.push_back(score);
  }

  return out;
}