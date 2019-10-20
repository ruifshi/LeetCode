#include "stdafx.h"
#include "NumberOfDiceRollsWithTargetSum.h"

using namespace std;

//We memoise the previously computed results for dice i and and target.
int dp[31][1001] = {};

// Since dp is initialized with zeros, we store there res + 1 to check if the result has been pre-computed. This is an optimization for brevity and speed.
int Solution::numRollsToTarget(int d, int f, int target) {
	int res = 0;
	if (d == 0 || target <= 0) return d == target;
	if (dp[d][target]) return dp[d][target] - 1;
	for (auto i = 1; i <= f; ++i)
		res = (res + numRollsToTarget(d - 1, f, target - i)) % 1000000007;
	dp[d][target] = res + 1;
	return res;
}

/*A basic brute-force solution could be to try all combinations of all faces for all dices, and count the ones that give a total sum of target.
Runtime: O(f ^ d).
Memory: O(d) for the stack.

int numRollsToTarget(int d, int f, int target, int res = 0) {
  if (d == 0 || target <= 0) return d == target;
  for (auto i = 1; i <= f; ++i)
	res = (res + numRollsToTarget(d - 1, f, target - i)) % 1000000007;
  return res;
}
*/