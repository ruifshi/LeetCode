#include "stdafx.h"
#include "MinimumCostToMergeStones.h"

#include <algorithm>

/*
Say the size of stones be N, since after each merging the number of piles will subtract (K - 1), and finally we get 1 pile, so it shows that only if (N-1) mod (K-1)==0 then it's possible to merge those piles into 1.
dp[l][i] represents the minimal cost to merge the piles in interval [i,i+l), here, we merge piles as much as possible. So, when l < 1+(K-1), we don't merge any piles, so dp[i][i+l] = 0; when 1+(K-1) <= l < 1+2(K - 1), we merge once; when 1+2(K-1) <= l < 1+3(K-1), we merge twice, and so on so forth.
Let's see for a certain interval length l, how can we get dp[l][i]. After all mergings, if we consider the leftmost pile in interval [i,i+l), then the status of this pile will show as below:

No merging happens in this pile, so it contains 1 original pile, let k = 1, then the cost is dp[k][i]+dp[l-k][i+k].
One merging happens in this pile, so it contains 1+(K-1) original piles, let k = 1+(K-1), then the cost is dp[k][i]+dp[l-k][i+k].
Two mergings happen in this pile, so it contains 1+2(K-1) original piles, let k = 1+2(K-1), then the cost is dp[k][i]+dp[l-k][i+k].
.......
When (l-1) mod (K-1)==0, we can see all piles in interval [i,i+l) can be finally merged into one pile, and the cost of the last merging is sum(stones[j]) for j in [i,i+l), regardless of the merging choices before the last one. And this "last cost" happens if and only if (l-1) mod (K-1)==0
*/
int Solution::mergeStones(vector<int>& stones, int K) {
	int N = (int)stones.size();
	if ((N - 1) % (K - 1)) return -1;

	vector<int> sum(N + 1, 0);
	for (int i = 0; i < N; i++) sum[i + 1] = sum[i] + stones[i];

	vector<vector<int> > dp(N + 1, vector<int>(N, 0));
	for (int l = K; l <= N; l++)
		for (int i = 0; i + l <= N; i++)
		{
			dp[l][i] = 10000;
			for (int k = 1; k < l; k += K - 1)
				dp[l][i] = min(dp[l][i], dp[k][i] + dp[l - k][i + k]);
			if ((l - 1) % (K - 1) == 0) dp[l][i] += sum[i + l] - sum[i];
		}
	return dp[N][0];
}