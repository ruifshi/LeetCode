#include "stdafx.h"
#include "KthLargestElementInAStream.h"

KthLargest::KthLargest(int k, vector<int>& nums) {
  for (int i = 0; i < nums.size(); i++) {
    pq.push(nums[i]);
    if (pq.size() > k) pq.pop();
  }
  size = k;
  return;
}

int KthLargest::add(int val) {
  pq.push(val);
  if (pq.size() > size) pq.pop();
  return pq.top();
}