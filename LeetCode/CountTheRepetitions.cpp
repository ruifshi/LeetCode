#include "stdafx.h"
#include "CountTheRepetitions.h"

/*
According to the question, we need to find mm such that [S2,m][S2,m] is the largest subsequence that can be found in S1S1. 
S2S2 is essentially [s2,n2][s2,n2] and S1S1 is [s1,n1][s1,n1] and so, we can find the number of times s2s2 repeats in 
[s1,n1][s1,n1], say \text{repeat_count}. And the number of times S2S2 repeats in S1S1 is therefore \text{(repeat_count/n2)}.
*/
int Solution::getMaxRepetitions(string s1, int n1, string s2, int n2) {
  int index = 0, repeat_count = 0;
  int s1_size = s1.size(), s2_size = s2.size();
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < s1_size; j++) {
      if (s1[j] == s2[index])
        ++index;
      if (index == s2_size) {
        index = 0;
        ++repeat_count;
      }
    }
  }
  return repeat_count / n2;
}

//https://leetcode.com/problems/count-the-repetitions/solution/
/*
int getMaxRepetitions(string s1, int n1, string s2, int n2)
{
  if (n1 == 0)
    return 0;
  int indexr[s2.size() + 1] = { 0 }; // index at start of each s1 block
  int countr[s2.size() + 1] = { 0 }; // count of repititions till the present s1 block
  int index = 0, count = 0;
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < s1.size(); j++) {
      if (s1[j] == s2[index])
        ++index;
      if (index == s2.size()) {
        index = 0;
        ++count;
      }
    }
    countr[i] = count;
    indexr[i] = index;
    for (int k = 0; k < i; k++) {
      if (indexr[k] == index) {
        int prev_count = countr[k];
        int pattern_count = (countr[i] - countr[k]) * (n1 - 1 - k) / (i - k);
        int remain_count = countr[k + (n1 - 1 - k) % (i - k)] - countr[k];
        return (prev_count + pattern_count + remain_count) / n2;
      }
    }
  }
  return countr[n1 - 1] / n2;
}
*/