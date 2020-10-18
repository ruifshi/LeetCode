#include "stdafx.h"
#include "RepeatedSubstringPattern.h"

/*
PatternPattern --> PatternPatternPatternPattern

Pattern1Pattern2 --> Pattern1Pattern2Pattern1Pattern2

Now let's cut the first and the last characters in the doubled string:

PatternPattern --> *atternPatternPatternPatter*

Pattern1Pattern2 --> *attern1Pattern2Pattern1Pattern*

It's quite evident that if the new string contains the input string, the input string is a repeated pattern string.
*/

bool Solution::repeatedSubstringPattern(string s) {
  return (s + s).substr(1, 2 * s.size() - 2).find(s) != string::npos;
}