#include "stdafx.h"
#include "TopKFrequentElements.h"

#include <unordered_map>
#include <queue>

vector<int> Solution::topKFrequent(vector<int>& nums, int k) {
  unordered_map<int, int> map;
  for (int num : nums) {
    map[num]++;
  }

  vector<int> res;
  /** use the priority queue, like the max-heap , we will keep (size-k) smallest elements in the queue**/
  /** pair<first, second>: first is frequency,  second is number **/
  priority_queue<pair<int, int>> pq;
  for (auto x : map) {
    pq.push(make_pair(x.second, x.first));
    /** onece the size bigger than size-k, we will pop the value, which is the top k frequent element value **/
    if (pq.size() > (int)map.size() - k) {
      res.push_back(pq.top().second);
      pq.pop();
    }
  }
  return res;
}