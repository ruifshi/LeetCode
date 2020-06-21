#include "stdafx.h"
#include "CustomSortString.h"

#include <vector>

string customSortString(string S, string T) {
  // keep track of number of chars that appear in T
  vector<int> count(26, 0);

  for (char &c : T) {
    count[c - 'a']++;
  }

  string ans;

  // write all chars that in both S and T in order of S
  for (char &c : S) {
    for (int i = 0; i < count[c - 'a']; i++) {
      ans += c;
    }

    // don't use this char again
    count[c - 'a'] = 0;
  }

  // get rest of T
  for (int i = 0; i < count.size(); i++) {
    for (int j = 0; j < count[i]; j++) {
      ans += i + 'a';
    }
  }

  return ans;
}