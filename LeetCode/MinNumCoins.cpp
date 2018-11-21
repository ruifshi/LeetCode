#include "stdafx.h"
#include "MinNumCoins.h"
#include "limits.h"
#include "stdlib.h"

int coinChange(int* coins, int coinsSize, int amount) {
    int *minNumCoins;
    int i, j, val;
    
	minNumCoins = (int*)malloc(sizeof(int)*(amount+1));

    for(i = 0; i < amount + 1; i++) {
        minNumCoins[i] = INT_MAX;
    }
    
    minNumCoins[0] = 0;
    
    for(i = 1; i <= amount; i++) {
        for(j = 0; j < coinsSize; j++) {
            if(coins[j] <= i) {
                val = minNumCoins[i-coins[j]];
                if (val != INT_MAX && val + 1 < minNumCoins[i]) 
                    minNumCoins[i] = val + 1;
            }
        }
    }
    
    if(minNumCoins[amount] != INT_MAX) {
        return minNumCoins[amount];
    }
    else {
        return -1;
    }
}