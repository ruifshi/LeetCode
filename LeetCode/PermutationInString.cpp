#include "stdafx.h"
#include "PermutationInString.h"

#include <unordered_map>

// O(n), O(1) since bounded alphabet
bool checkInclusion(string s1, string s2) {
  int size1 = s1.size();
  int size2 = s2.size();

  if (size1 > size2) return false;

  unordered_map<char, int> s1map;
  unordered_map<char, int> s2map;

  for (int i = 0; i < size1; i++) {
    s1map[s1[i]]++;
    s2map[s2[i]]++;
  }

  // use sliding window on s2 to match s1
  for (int i = 0; i < size2 - size1; i++) {
    if (s1map == s2map) return true;

    //add letter at end of window
    s2map[s2[i + size1]]++;
    //remove letter at beginning
    s2map[s2[i]]--;
    if (s2map[s2[i]] == 0) s2map.erase(s2[i]);
  }

  return s1map == s2map;
}