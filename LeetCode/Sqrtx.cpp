#include "stdafx.h"
#include "Sqrtx.h"

int Solution::mySqrt(int x) {
    long r = x;
    while (r*r > x)
		r = (r + x/r) / 2;
    return r;
}