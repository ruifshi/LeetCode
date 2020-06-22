#include "stdafx.h"
#include "ValidWordAbbreviation.h"

bool Solution::validWordAbbreviation(string word, string abbr) {
  int idxW = 0;
  int idxA = 0;

  while (idxW < word.size() && idxA < abbr.size()) {
    //If abbr starts with 0, then invalid
    if (isdigit(abbr[idxA]) && abbr[idxA] == '0') return false;

    //get next digit
    int num = 0;
    while (idxA < abbr.size() && isdigit(abbr[idxA])) {
      num = num * 10 + abbr[idxA] - '0';
      idxA++;
    }

    // move idxW forward in words to match location
    idxW += num;

    //check if current locations are matched or not for validity
    
    //the numbers extend to end of word
    if (idxW == word.size() && idxA == abbr.size()) return true;
    //check matching
    else if (idxW == word.size() || idxA == abbr.size() || word[idxW] != abbr[idxA]) return false;

    idxW++;
    idxA++;
  }

  return idxW == word.size() && idxA == abbr.size();
}