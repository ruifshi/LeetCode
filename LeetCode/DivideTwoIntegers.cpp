#include "stdafx.h"
#include "DivideTwoIntegers.h"

#include <limits>

// O(logn)
int Solution::divide(int dividend, int divisor) {
	if (dividend == INT_MIN && divisor == -1) {
		return INT_MAX;
	}
	int sign;

	if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0)) sign = 1;
	else sign = -1;

	long dvd = labs(dividend), dvs = labs(divisor), ans = 0;

	while (dvd >= dvs) {
		long temp = dvs, m = 1;
		while (temp << 1 <= dvd) {
			temp <<= 1; // partial divident
			m <<= 1;    // number of times divided by 2 + final
		}
		dvd -= temp;
		ans += m;
	}
	return sign == 1 ? ans : -ans;
}

/* O(n)
public int divide(int dividend, int divisor) {
    int quotient = 0;
    while (dividend - divisor >= 0) {
        quotient++;
        dividend -= divisor;
    }
    return quotient;
}
*/