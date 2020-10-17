#pragma once

#include <vector>
#include <queue>

using namespace std;

class KthLargest {
private:
  priority_queue<int, vector<int>, greater<int>> pq;
  int size;

public:
  KthLargest(int k, vector<int>& nums);

  int add(int val);
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */