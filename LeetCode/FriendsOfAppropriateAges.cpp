#include "stdafx.h"
#include "FriendsOfAppropriateAges.h"

#include <unordered_map>

bool request(int a, int b) {
  if (b <= 0.5 * a + 7) return false;
  if (b > a) return false;
  if (b > 100 && a < 100) return false;
  return true;
}

int Solution::numFriendRequests(vector<int>& ages) {
  unordered_map<int, int> count;
  for (int &age : ages)
    count[age]++;
  int res = 0;
  for (auto &a : count)
    for (auto &b : count)
      if (request(a.first, b.first))
        // remove self requests example: [16, 16] 2 * 2 - 2
        res += a.second * (b.second - (a.first == b.first ? 1 : 0)); 
  return res;
}