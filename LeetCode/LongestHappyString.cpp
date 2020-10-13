#include "stdafx.h"
#include "LongestHappyString.h"

#include <queue>

/*
For the letter has the max count, we greedily take 2 chars. But for the letter didn't has the max count, we just take 1 char. 
The reason is, the letter with less count, would be used as delimiter. To have the longest happy string, we want to greedily do two things.

* Use as many as possible chars which has the max count.
* To achieve 1, we need to have as many as much delimiter.


Create a max heap of the form pair<int,char> to store the count of each character.
while (pq.size()>1)Pop out the first 2 pair who have the max frequency.
Add greedily the occurances of the first pair to the ans and update it's count.
For the second pair, compare it's occurances with the first pair and add accordingly.
Finally add the pairs to the Max Heap if their count>0.
If pq.empty() return ans, else add the leftover character to the ans according to the remaining counts and return the ans.
*/

string Solution::longestDiverseString(int a, int b, int c) {
  //using max heap
  priority_queue<pair<int, char>>pq;
  if (a)
    pq.push({ a,'a' });
  if (b)
    pq.push({ b,'b' });
  if (c)
    pq.push({ c,'c' });
  string ans = "";
  while (pq.size() > 1) {
    pair<int, char>one = pq.top();pq.pop();
    pair<int, char>two = pq.top();pq.pop();

    ans += string(one.first >= 2 ? 2 : 1, one.second);
    one.first -= one.first >= 2 ? 2 : 1;

    ans += string((two.first >= 2 && two.first >= one.first) ? 2 : 1, two.second);
    two.first -= (two.first >= 2 && two.first >= one.first) ? 2 : 1;

    if (one.first > 0) pq.push(one);
    if (two.first > 0) pq.push(two);
  }

  if (pq.empty()) return ans;
  ans += string(pq.top().first >= 2 ? 2 : 1, pq.top().second);

  return ans;
}