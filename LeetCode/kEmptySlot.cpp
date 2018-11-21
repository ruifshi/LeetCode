#include "stdafx.h"
#include "kEmptySlot.h"
#include "stdlib.h"
#include "string.h"

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
