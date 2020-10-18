#include "stdafx.h"
#include "4SumII.h"

#include <unordered_map>

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
  int cnt = 0;
  unordered_map<int, int> m;
  for (int a : A)
    for (int b : B)
      ++m[a + b];
  for (int c : C)
    for (int d : D) {
      auto it = m.find(-(c + d));
      if (it != end(m))
        cnt += it->second;
    }
  return cnt;
}

/*
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    return kSumCount(vector<vector<int>>() = {A, B, C, D});
}
int kSumCount(vector<vector<int>> &lists) {
    unordered_map<int, int> m;
    addToHash(lists, m, 0, 0);
    return countComplements(lists, m, lists.size() / 2, 0);
}
void addToHash(vector<vector<int>> &lists, unordered_map<int, int> &m, int i, int sum) {
    if (i == lists.size() / 2)
        ++m[sum];
    else
        for (int a : lists[i])
            addToHash(lists, m, i + 1, sum + a);
}
int countComplements(vector<vector<int>> &lists, unordered_map<int, int> &m, int i, int complement) {
    if (i == lists.size()) {
        auto it = m.find(complement);
        return it == end(m) ? 0 : it->second;
    }
    int cnt = 0;
    for (int a : lists[i])
        cnt += countComplements(lists, m, i + 1, complement - a);
    return cnt;
}
*/