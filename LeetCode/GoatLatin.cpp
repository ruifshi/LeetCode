#include "stdafx.h"
#include "GoatLatin.h"

string Solution::toGoatLatin(string S) {
  string ret, suffix;
  for (int i = 0; i < S.length(); i++)
  {
    int start = i;
    while (i < S.length() && S[i] != ' ') i++;

    if (S[start] == 'a' || S[start] == 'e' || S[start] == 'i' || S[start] == 'o' || S[start] == 'u' || S[start] == 'A' ||
      S[start] == 'E' || S[start] == 'I' || S[start] == 'O' || S[start] == 'U') {
      ret += S.substr(start, i - start) + "ma";
    }
    else {
      ret += S.substr(start + 1, i - start - 1) + S[start] + "ma";
    }
    suffix += 'a';
    ret += suffix + " ";
  }
  ret.pop_back(); // remove last space
  return ret;
}