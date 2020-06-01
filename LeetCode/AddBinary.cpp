#include "stdafx.h"
#include "AddBinary.h"

string Solution::addBinary(string a, string b) {
  int i = a.size() - 1, j = b.size() - 1, carry = 0;
  string s;

  while (i >= 0 || j >= 0 || carry) {
    int sum = carry;
    if (i >= 0) { sum += a[i] - '0'; i--; }
    if (j >= 0) { sum += b[j] - '0'; j--; }
    carry = sum / 2;
    sum = sum % 2;
    s += sum + '0';
  }

  reverse(s.begin(), s.end());

  return s;
}