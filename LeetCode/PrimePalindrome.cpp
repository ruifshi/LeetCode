#include "stdafx.h"
#include "PrimePalindrome.h"

#include <string>

using namespace std;

int Solution::primePalindrome(int N) {
	if (N <= 2) return 2;
	if (N >= 8 && N <= 11) return 11;
	for (int i = 1; i <= 1000000; i++) {
		int num = MakePalindrome(i);
		if (num >= N && check(num)) {
			return num;
		}
	}
	return -1;
}

int Solution::MakePalindrome(int x) {
	string s = to_string(x);
	string t = s;
	reverse(t.begin(), t.end());
	s.pop_back();
	return stoi(s + t);
}

bool Solution::check(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}