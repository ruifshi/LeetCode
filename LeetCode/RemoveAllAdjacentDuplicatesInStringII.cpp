#include "stdafx.h"
#include "RemoveAllAdjacentDuplicatesInStringII.h"

#include <vector>

// keep track of duplicate character count in vector
// once we reach k, remove that element from the vector
// whatever is left is the non dup characters
string Solution::removeDuplicates(string s, int k) {
  vector<pair<int, char>> counts;
  for (int i = 0; i < s.size(); ++i) {
    if (counts.empty() || s[i] != counts.back().second) {
      counts.push_back({ 1, s[i] });
    }
    else if (++counts.back().first == k) {
      counts.pop_back();
    }
  }
  s = "";
  for (auto &p : counts) {
    s += string(p.first, p.second);
  }
  return s;
}

/* O(n) stack keeps count of prev duplicates until we reach k
string removeDuplicates(string s, int k) {
    stack<int> counts;
    for (int i = 0; i < s.size(); ++i) {
        if (i == 0 || s[i] != s[i - 1]) {
            counts.push(1);
        } else if (++counts.top() == k) {
            counts.pop();
            s.erase(i - k + 1, k);
            i = i - k;
        }
    }
    return s;
}
*/

/* brute force O(n^2/k)
string removeDuplicates(string s, int k) {
    int length = -1;
    while (length != s.size()) {
        length = s.size();
        for (int i = 0, count = 1; i < s.size(); ++i) {
            if (i == 0 || s[i] != s[i - 1]) {
                count = 1;
            } else if (++count == k) {
                s.erase(i - k + 1, k);
                break;
            }
        }
    }
    return s;
}
*/