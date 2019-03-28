#include "stdafx.h"
#include "kEmptySlot.h"
#include "stdlib.h"
#include "string.h"

/*
bool windowFound(int *currBloom, int flowerSize, int k) {
	int i, j, count;
	bool found = false;

	for(i = 1; i + k < flowerSize; i=i++) {
		if(currBloom[i-1] == 1 && currBloom[i+k] == 1)
		{
			count = 0;
			for(j = i; j < i + k; j++) {
				if(currBloom[j] == 0) {
					count++;
				}
			}
			if(count == k) {
				return true;
			}
		}
	}

	return found;
}

int kEmptySlots(int* flowers, int flowersSize, int k) {
    int i;
	int *currBloom;

	currBloom = (int*)malloc(sizeof(int)*flowersSize);
	memset(currBloom, 0, sizeof(int)*flowersSize);

	for(i = 0; i < flowersSize; i++) {
		currBloom[flowers[i]-1] = 1;
		if(windowFound(currBloom, flowersSize, k)) {
			free(currBloom);
			return i+1;
		}
	}

	free(currBloom);
	return -1;
}
*/

// O(n)
int kEmptySlots(int* flowers, int flowersSize, int k) {
	int *days = (int*)malloc(sizeof(int)*flowersSize);
	int i, left = 0, right = k + 1, result = INT_MAX;

	// create an array that tells the day of bloom when given a position
	for(i = 0; i < flowersSize; i++) {
		days[flowers[i] - 1 ] = i + 1;
	}

	// If the day at position x is grater than the day for the positions
	// on the left and right boundaries, and right - left + 1 = k, then
	// that means on the right position's day is a candidate.
	for(i = 0; right < flowersSize; i++) {
		if(days[i] > days[left] && days[i] > days[right]) {
			continue;
		}
		if(i == right) {
			result = result < (days[left] < days[right] ? days[right] : days[left]) ? result : (days[left] < days[right] ? days[right] : days[left]);
		}
		left = i;
		right = i + k + 1;
	}

	return result;
}

/* O(nlogn)
class Solution {
public:
	int kEmptySlots(vector<int>& flowers, int k) {
	   set<int> pos_set;
	   pos_set.insert(flowers.front());
	   for(int i=1; i<flowers.size(); i++){
		   auto it = pos_set.insert(flowers[i]).first;	// first points to newly inserted element or the existing one already in the set
		   if(it != pos_set.begin()){
			   if(*it - *prev(it)-1 == k){
				   return i+1;
			   }
		   }
		   if(next(it) != pos_set.end()){
			   if(*next(it) - *it -1 == k){
				   return i+1;
			   }
		   }
	   }
	   return -1;
	}
};
*/