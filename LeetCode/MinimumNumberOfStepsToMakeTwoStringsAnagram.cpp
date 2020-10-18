#include "stdafx.h"
#include "MinimumNumberOfStepsToMakeTwoStringsAnagram.h"

#include <unordered_map>

int Solution::minSteps(string s, string t) {
  unordered_map<char, int>m;
  int sum = 0;
  for (auto i : s)
    m[i]++;
  for (auto i : t)
    m[i]--;
  for (auto i : m) {
    if (i.second < 0) //greater or less are the same
      sum += i.second;
  }
  return abs(sum);
}

/*
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> m (26);
        int sum=0;
        for(auto c:s)
            m[c - 'a']++;
        for(auto c:t)
            m[c - 'a']--;

        for (int i = 0; i < 26; i++)
        {
            if (m[i] < 0) {
                //char exist in t not s
                sum += m[i];
            }
        }
        return abs(sum);
    }
};
*/