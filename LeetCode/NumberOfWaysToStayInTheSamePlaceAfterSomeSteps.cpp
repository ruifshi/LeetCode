#include "stdafx.h"
#include "NumberOfWaysToStayInTheSamePlaceAfterSomeSteps.h"

#include <vector>
#include <algorithm>

using namespace std;

/*
How can we reach the current position in 1 step?

come from left cell
come from right cell
stay in this cell
The total number of ways is the sum of these 3 ways for the previous step.
We should repeat this for each cell and each step.
*/
int Solution::numWays(int steps, int arrLen) {
  int size = min(steps / 2 + 1, arrLen);  // /2 to make sure we can come back
  vector<int> dp(size + 2, 0);
  dp[1] = 1;
  int s = 1;
  int mod = 1000000007;
  while (s <= steps) {

    int left = dp[0], above = dp[1];
    int right = dp[2];

    for (int i = 1; i <= size; i++) {
      dp[i] = ((left + above) % mod + right) % mod;
      left = above;
      above = right;
      right = dp[i + 2];
      if (s == steps)
        break;
    }
    s++;
  }
  return dp[1];
}