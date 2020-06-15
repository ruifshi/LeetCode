#include "stdafx.h"
#include "FindTheCelebrity.h"

bool knows(int a, int b) {
  return true;
}

/*
The following algorithm can, therefore, be used to rule out n - 1 of the people in O(n) time. 
We start by guessing that 0 might be a celebrityCandidate, and then we check if 0 knows 1 (within the loop). 
If true, then we know 0 isn't a celebrity (they know somebody), but 1 might be. We update the celebrityCandidate 
variable to 1 to reflect this. Otherwise, we know 1 is not a celebrity (somebody doesn't know them), 
but we haven't ruled out 0, yet, so keep them as the celebrityCandidate. Whoever we kept is then asked if they know 2, and so forth.
*/
bool isCeleb(int i, int n) {
  for (int j = 0; j < n; j++) {
    if (i == j) continue; // Don't ask if they know themselves.
    if (knows(i, j) || !knows(j, i)) {
      return false;
    }
  }
  return true;
}

int Solution::findCelebrity(int n) {
  int candidate = 0;

  for (int i = 0; i < n; i++) {
    if (knows(candidate, i)) {  // candidate knows i
      candidate = i;
    }
  }

  if (isCeleb(candidate, n)) {
    return candidate;
  }

  return -1;
}

/* brute force O(n^2)
public class Solution extends Relation {

    private int numberOfPeople;

    public int findCelebrity(int n) {
        numberOfPeople = n;
        for (int i = 0; i < n; i++) {
            if (isCelebrity(i)) {
                return i;
            }
        }
        return -1;
    }

    private boolean isCelebrity(int i) {
        for (int j = 0; j < numberOfPeople; j++) {
            if (i == j) continue; // Don't ask if they know themselves.
            if (knows(i, j) || !knows(j, i)) {
                return false;
            }
        }
        return true;
    }
}
*/