#include "stdafx.h"
#include "PlusOne.h"

vector<int> Solution::plusOne(vector<int>& digits) {
	if(digits.empty()) {
		return digits;
	}

	int carry = 0;

	digits[digits.size() - 1] = ((digits[digits.size() - 1] + 1) % 10);

	if(digits[digits.size() - 1] % 10 == 0) {
		carry = 1;
	}


	for(int i = digits.size() - 2; i >= 0; i--) {
		if(carry == 1) {
			digits[i] = (digits[i] + 1) % 10;
			carry = 0;
			if(digits[i] == 0) {
				carry = 1;
			}
		}
	}

	if(carry == 1) {
		digits.insert(digits.begin(), 1);
	}

	return digits;
}