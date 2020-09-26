#include "stdafx.h"
#include "AnalyzeUserWebsiteVisitPattern.h"

#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>

vector<string> Solution::mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
  unordered_map<string, vector<pair<int, string>>> mp;  //maps username to timestamp + site
  set<vector<string>> seqs; // need to use set instead of unordered to use vector as key, otherwise, need hash fn
  map<vector<string>, int> seqCount;  // map instead of unordered

  //generate user to timestamp + site
  for (int i = 0; i < username.size(); i++) {
    mp[username[i]].push_back(make_pair(timestamp[i], website[i]));
  }

  for (auto ele : mp) {
    //sort visits of each user by timestamp for ascending order
    vector<pair<int, string>> visits = ele.second;
    sort(visits.begin(), visits.end(), [](pair<int, string>& a, pair<int, string>& b) {
      return (a.first < b.first);
    });

    //generate all possible 3-seqs of the webistes for each user
    seqs.clear(); // needs to be a set to prevent duplicates
    for (int i = 0; i < visits.size(); i++) {
      for (int j = 0; j < i; j++) {
        for (int k = 0; k < j; k++) {
          seqs.insert({ visits[k].second, visits[j].second, visits[i].second });
        }
      }
    }

    //keep track of all the 3-seq counts
    for (auto seq : seqs) seqCount[seq]++;
  }

  // find the sequence with largest count
  int max = 0;
  vector<string> out;
  for (auto ele : seqCount) {
    if (ele.second > max) {
      max = ele.second;
      out = ele.first;
    }
  }

  return out;
}