#include "stdafx.h"
#include "PlusOne.h"

// O(n)
vector<int> Solution::plusOne(vector<int>& digits) {
	if(digits.empty()) {
		return digits;
	}

	int carry = 0;

	// increment the last digit by 1. %10 to prevent overflow
	digits[digits.size() - 1] = ((digits[digits.size() - 1] + 1) % 10);

	// if last digits was 9, keep track of the carry for next add
	if(digits[digits.size() - 1] % 10 == 0) {
		carry = 1;
	}
	else {
		return digits;
	}

	// move to next digits
	for(int i = digits.size() - 2; i >= 0; i--) {
		// add carry to next digits and keep track of future carries
		if(carry == 1) {
			digits[i] = (digits[i] + 1) % 10;
			carry = 0;
			if(digits[i] == 0) {
				carry = 1;
			}
		}
	}

	// If there is a carry remaining, then we need to add it to MSD
	if(carry == 1) {
		digits.insert(digits.begin(), 1);
	}

	return digits;
}