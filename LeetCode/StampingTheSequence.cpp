#include "stdafx.h"
#include "StampingTheSequence.h"

/*
It's better explained through an example. Let's say the target is 'aabccbc', 
and stamp is 'abc'. We first try to find 'abc' and replace it with '***'. 
After there are no more replacements, we will try '*bc' and 'ab*', and so on. Now, turn by turn:

'aabccbc' ? 'abc' = [1]
'a***cbc' ? '*bc' = []
'a***cbc' ? 'ab*' = []
'a***cbc' ? 'a**' = [0]
'****cbc' ? '*b*' = []
'****cbc' ? '**c' = [2]
'*****bc' ? '*bc' = [4]
*/
vector<int> Solution::movesToStamp(string stamp, string target) {
  vector<int> res;
  int total_stamp = 0, turn_stamp = -1;
  while (turn_stamp) {
    turn_stamp = 0;
    for (int sz = stamp.size(); sz > 0; --sz)
      for (int i = 0; i <= stamp.size() - sz; ++i) {
        string new_stamp = string(i, '*') + stamp.substr(i, sz) + string(stamp.size() - sz - i, '*');
        int pos = target.find(new_stamp);
        while (pos != string::npos) {
          res.push_back(pos);
          turn_stamp += sz;
          fill(begin(target) + pos, begin(target) + pos + stamp.size(), '*');
          pos = target.find(new_stamp);
        }
      }
    total_stamp += turn_stamp;
  }
  reverse(begin(res), end(res));
  return total_stamp == target.size() ? res : vector<int>();
}