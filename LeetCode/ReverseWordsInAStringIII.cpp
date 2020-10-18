#include "stdafx.h"
#include "ReverseWordsInAStringIII.h"

string reverseWords3(string s) {
  if (s.length() == 0) return "";

  int start = 0, end = 0;
  while ((end = s.find(" ", start)) != string::npos) {
    reverse(s.begin() + start, s.begin() + end);
    start = end + 1;
  }
  reverse(s.begin() + start, s.begin() + s.length());

  return s;
}