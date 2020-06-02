#include "stdafx.h"
#include "Stock.h"
#include "limits.h"

int maxProfit(int* prices, int pricesSize) {
  int maxProfit = 0;
	int minPrice = INT_MAX;
	int	i;
    
	if(pricesSize <= 1) {
		return maxProfit;
	}

	for(i = 0; i < pricesSize; i++) {
		if(prices[i] < minPrice) {
			minPrice = prices[i];
		}
		else if((prices[i] - minPrice) > maxProfit) {
			maxProfit = prices[i] - minPrice;
		}
	}

	return maxProfit;
}