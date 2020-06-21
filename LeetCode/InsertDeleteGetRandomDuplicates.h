#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class RandomizedCollection {
public:
  /** Initialize your data structure here. */
  RandomizedCollection();

  /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
  bool insert(int val);

  /** Removes a value from the collection. Returns true if the collection contained the specified element. */
  bool remove(int val);

  /** Get a random element from the collection. */
  int getRandom();

private:
  vector<int> nums;
  unordered_map<int, unordered_set<int>> m;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */