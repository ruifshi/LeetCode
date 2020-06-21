#include "stdafx.h"
#include "InsertDeleteGetRandomDuplicates.h"

/*
  // values to pick from
  vector<int> nums;

  // values in array to indices where they are
  unordered_map<int, unordered_set<int>> m;
*/

/** Initialize your data structure here. */
RandomizedCollection::RandomizedCollection() {

}

/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
bool RandomizedCollection::insert(int val) {
  bool ret_val = true;

  // duplicate number
  if (m.find(val) != m.end()) ret_val = false;

  nums.push_back(val);
  m[val].insert(nums.size() - 1);

  return ret_val;
}

// swap last value with value to be removed
/** Removes a value from the collection. Returns true if the collection contained the specified element. */
bool RandomizedCollection::remove(int val) {
  if (m.find(val) == m.end()) {
    return false;
  }
  else {
    // get an index from set for val to be removed
    int index_remove = *m[val].begin();

    // move last number in array to index to be removed
    int last = nums.back();
    nums[index_remove] = nums[nums.size() - 1];

    // remove the index of val from set
    m[val].erase(index_remove);

    // put number from last index to old location of removed val
    m[last].insert(index_remove);
    // remove the old index of the last number
    m[last].erase(nums.size() - 1);

    nums.pop_back();

    if (m[val].size() == 0) m.erase(val);
    return true;
  }
}

/** Get a random element from the collection. */
int RandomizedCollection::getRandom() {
  return nums[rand() % nums.size()];
}