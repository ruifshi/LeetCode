#include "stdafx.h"
#include "LongestArithmeticSequence.h"

#include <unordered_map>
#include <algorithm>

int Solution::longestArithSeqLength(vector<int>& A) {
  int n = A.size();
  if (n <= 2) return n;

  // dp[val][diff] means the number of elements in sequence 
  // whose lost element is val and difference is diff
  vector<unordered_map<int, int>> dp(n);

  int maxLen = 2; // at least 2 since n > 2
  
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int diff = A[j] - A[i];

      // we've seen this difference before in previous sequence
      if (dp[i].find(diff) != dp[i].end()) {
        dp[j][diff] = dp[i][diff] + 1;  // add 1 to previous sequence size and log it
      }
      else {
        dp[j][diff] = 2;  //at least 2 since i and j
      }

      maxLen = max(maxLen, dp[j][diff]);
    }
  }

  return maxLen;
}