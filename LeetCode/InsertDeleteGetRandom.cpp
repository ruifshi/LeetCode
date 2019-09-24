#include "stdafx.h"
#include "InsertDeleteGetRandom.h"

/*
Usually the first thing that comes to find when we hear "lookup" , "insert" in constant time is "hashmaps".
That's the reason we use an unordered_map here which stores the element as " key " and its position in vector as the "value ".. The average time complexity of search , insert and remove elements from a hashmap is O(1).

However , here we need to support "Random()" access in O(1) as well. so we are using a vector here to achieve that.

Now the code is fairly simple to understand if you read it, but there is a trick to remove the element in O(1) time from a vector.
This trick is very commonly used in competitive programming , so its ok if you could come up with it by yourself :-)

Here is the trick to remove in constant time.
Assume that the order of elements does not matter.
This is what you need to pay attention to.

Suppose you have a vector

0 1 2 3 4 5 6
and you want to remove the 3. You can turn this into

0 1 2 6 4 5
in O(1) without any issues.

Here is the pseudo-code

If the element you are trying to remove is the last element in the vector, remove it, done.
Read the last element of the vector and write it over the element-to-be-removed.
Remove the last element of the vector.
That is exactly the trick we are using here, only that we need to update our hashmap as well.
*/

/** Initialize your data structure here. */
RandomizedSet::RandomizedSet() {

}

/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
bool RandomizedSet::insert(int val) {
	if (m.find(val) != m.end()) return false;
	nums.emplace_back(val);
	m[val] = nums.size() - 1;
	return true;
}

/** Removes a value from the set. Returns true if the set contained the specified element. */
bool RandomizedSet::remove(int val) {
	if (m.find(val) == m.end()) return false;
	int last = nums.back();
	m[last] = m[val];
	nums[m[val]] = last;
	nums.pop_back();
	m.erase(val);
	return true;
}

/** Get a random element from the set. */
int RandomizedSet::getRandom() {
	return nums[rand() % nums.size()];
}