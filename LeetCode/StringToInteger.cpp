#include "stdafx.h"
#include "StringToInteger.h"

int Solution::myAtoi(string str) {
  int size = str.size();
  int i = 0;

  // skip leading spaces
  while (i < size &&str[i] == ' ') {
    i++;
  }

  if (i == size) return 0;

  //handle sign if it exists
  bool isnegative = false;
  if (str[i] == '-') {
    isnegative = true;
    i++;
  }
  else if (str[i] == '+') {
    i++;
  }

  long num = 0;
  while (i < size && num < INT_MAX && isdigit(str[i])) {
    num = num * 10 + (str[i] - '0');
    i++;
  }

  if (num > INT_MAX) {
    return isnegative ? INT_MIN : INT_MAX;
  }

  return isnegative ? -num : num;
}