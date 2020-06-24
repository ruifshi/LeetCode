#include "stdafx.h"
#include "StringCompression.h"

#include <string>

int compress(vector<char>& chars) {
  int i = 0; // write pointer

  int count = 1; // since we start from j = 1
  // j is read pointer
  // count same char until we hit a different one
  for (int j = 1; j <= chars.size(); j++) {
    if (j == chars.size() || chars[j] != chars[j - 1]) {
      chars[i++] = chars[j - 1];
      if (count >= 2)
        // convert count to string and write the digits to the buffer
        for (char digit : to_string(count))
          chars[i++] = digit;
      count = 0;
    }
    count++;
  }
  return i;
}