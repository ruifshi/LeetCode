#include "stdafx.h"
#include "BestTimeToBuyAndSellStockII.h"

/*
This solution follows the logic used in Approach 2 itself, but with only a slight variation. 
In this case, instead of looking for every peak following a valley, we can simply go on crawling 
over the slope and keep on adding the profit obtained from every consecutive transaction. 
In the end,we will be using the peaks and valleys effectively, but we need not track the costs 
corresponding to the peaks and valleys along with the maximum profit, but we can directly keep 
on adding the difference between the consecutive numbers of the array if the second number is larger 
than the first one, and at the total sum we obtain will be the maximum profit. This approach will 
simplify the solution. This can be made clearer by taking this example:
*/
int Solution::maxProfit(vector<int>& prices) {
  int maxprofit = 0;
  for (int i = 1; i < prices.size(); i++) {
    if (prices[i] > prices[i - 1])
      maxprofit += prices[i] - prices[i - 1];
  }
  return maxprofit;
}