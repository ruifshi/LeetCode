#include "stdafx.h"
#include "ValidPalindromeIII.h"

#include <vector>
#include <algorithm>

/*
Now let dp[i][j] denote the minimum number of deletions to make the substring from i to j a Palindrome.

Two Possible Cases-

S[i]==S[j]
S[i]!=S[j]
Case 1:
If S[i]==S[j], then we make no deletions, so we only need to make the substring from
i+1 to j-1 a Palindrome , hence dp[i][j]=dp[i+1][j-1] .

Case 2:
If S[i]!=S[j], we need to delete either S[i] or S[j], whichever possibility gives the optimal solution , hence dp[i][j] = 1+min(dp[i+1][j],dp[i][j-1]).
*/
bool Solution::isValidPalindrome(string s, int k) {
  int n = s.length();
  // Basic Dynamic Programming

  int i, j;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

  // dp[i][j]=Minimum Number of deletions to make the Substring S[i to j] Palindrome
  // dp[i][i]=0 (a string of length 1 is always a Palindrome)

  for (j = 1;j <= n;j++)
  {
    i = j - 1;
    while (i >= 1)
    {
      if (s[i - 1] == s[j - 1])  // If S[i-1]==S[j-1]
      {
        // dp[i][j] = dp[i+1][j-1]
        // Because the Number of Deletions is 0
        if (j - i >= 2)
          dp[i][j] = dp[i + 1][j - 1];
        else
          dp[i][j] = 0;
      }
      else               //  If S[i-1]!=S[j-1]
      {
        // Two Possible Choices :-
        // 1. Delete S[i-1]
        // 2. Delete S[j-1]
        dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
      }
      i--;
    }
  }
  if (dp[1][n] <= k)
    return true;
  else
    return false;
}