#include "stdafx.h"
#include "AllOoneDataStructure.h"

//map<int, unordered_set<string>> reverse;
//unordered_map<string, int> table;

/** Initialize your data structure here. */
AllOne::AllOne() {

}

/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
void AllOne::inc(string key) {
  if (table.count(key)) {
    reverse[table[key]].erase(key);
    if (reverse[table[key]].empty()) {
      reverse.erase(table[key]);
    }
    table[key]++;
    reverse[table[key]].insert(key);
  }
  else {
    table[key] = 1;
    reverse[1].insert(key);
  }
}

/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
void AllOne::dec(string key) {
  if (table.count(key)) {
    reverse[table[key]].erase(key);
    if (reverse[table[key]].empty()) {
      reverse.erase(table[key]);
    }
    if (table[key] == 1) {
      table.erase(key);
    }
    else {
      table[key]--;
      reverse[table[key]].insert(key);
    }
  }
}

/** Returns one of the keys with maximal value. */
string AllOne::getMaxKey() {
  auto first = reverse.begin();
  if (first == reverse.end()) {
    return "";
  }
  else {
    return *(first->second.begin());
  }
}

/** Returns one of the keys with Minimal value. */
string AllOne::getMinKey() {
  auto last = reverse.rbegin();
  if (last == reverse.rend()) {
    return "";
  }
  else {
    return *(last->second.begin());
  }
}

/*
class AllOne {
public:
    void inc(string key) {

        // If the key doesn't exist, insert it with value 0.
        if (!bucketOfKey.count(key))
            bucketOfKey[key] = buckets.insert(buckets.begin(), {0, {key}});

        // Insert the key in next bucket and update the lookup.
        auto next = bucketOfKey[key], bucket = next++;
        if (next == buckets.end() || next->value > bucket->value + 1)
            next = buckets.insert(next, {bucket->value + 1, {}});
        next->keys.insert(key);
        bucketOfKey[key] = next;

        // Remove the key from its old bucket.
        bucket->keys.erase(key);
        if (bucket->keys.empty())
            buckets.erase(bucket);
    }

    void dec(string key) {

        // If the key doesn't exist, just leave.
        if (!bucketOfKey.count(key))
            return;

        // Maybe insert the key in previous bucket and update the lookup.
        auto prev = bucketOfKey[key], bucket = prev--;
        bucketOfKey.erase(key);
        if (bucket->value > 1) {
            if (bucket == buckets.begin() || prev->value < bucket->value - 1)
                prev = buckets.insert(bucket, {bucket->value - 1, {}});
            prev->keys.insert(key);
            bucketOfKey[key] = prev;
        }

        // Remove the key from its old bucket.
        bucket->keys.erase(key);
        if (bucket->keys.empty())
            buckets.erase(bucket);
    }

    string getMaxKey() {
        return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
    }

    string getMinKey() {
        return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
    }

private:
    struct Bucket { int value; unordered_set<string> keys; };
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> bucketOfKey;
};
*/