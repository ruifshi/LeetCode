#include "stdafx.h"
#include "QueueReconstructionByHeight.h"

#include <algorithm>

// sort people according to height first and k second
bool mycomp2(vector<int>& a, vector<int>& b) {
  if (a[0] == b[0]) {
    return a[1] < b[1];
  }
  return a[0] > b[0];
}

/* People are only counting(in their k - value) taller or equal - height others standing in front of them.So a smallest person is completely 
irrelevant for all taller ones.And of all smallest people, the one standing most in the back is even completely irrelevant for everybody else.
Nobody is counting that person.So we can first arrange everybody else, ignoring that one person.And then just insert that person appropriately.
Now note that while this person is irrelevant for everybody else, everybody else is relevant for this person - this person counts exactly 
everybody in front of them.So their count - value tells you exactly the index they must be standing.
*/
vector<vector<int>> Solution::reconstructQueue(vector<vector<int>>& people) {
  sort(people.begin(), people.end(), mycomp2);
  vector<vector<int>> ans;

  for (auto& p : people)
    ans.insert(ans.begin() + p[1], p);
  return ans;
}