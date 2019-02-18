#include "stdafx.h"
#include "Pow.h"

//O(log(N))
double Solution::myPow(double x, int n) {
	// long long for -2^31 since it overflows int
	long long N = n;
	// x^-2 = 1/x^2
	if (N < 0) {
		x = 1 / x;
		N = -N;
	}

	return myPowHelper(x, N);
}

double Solution::myPowHelper(double x, long long n) {
	// x^0 = 1
	if (n == 0) {
		return 1.0;
	}
	// for even number the reccurence relation is x^n/2 & x^n/2
	else if (n % 2 == 0) {
		double y = myPowHelper(x, n / 2);
		return y * y;
	}
	// for odd number the reccurence relation is x*x^n-1
	else {
		return x * myPowHelper(x, n - 1);
	}
}