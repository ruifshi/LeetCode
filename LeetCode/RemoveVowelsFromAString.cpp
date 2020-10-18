#include "stdafx.h"
#include "RemoveVowelsFromAString.h"

string Solution::removeVowels(string S) {
  string res = "";
  for (int i = 0; i < S.size();i++) {
    if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u' || S[i] == 'A' || S[i] == 'E' || S[i] == 'I' || S[i] == 'O' || S[i] == 'U') {
      continue;
    }
    else {
      res += S[i];
    }
  }
  return res;
}

/*
    string removeVowels(string S) {
      char c;
      for(auto it = S.begin(); it != S.end(); ++it)
      {
        c = *it;
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
          S.erase(it--);
      }
      return S;
    }
*/