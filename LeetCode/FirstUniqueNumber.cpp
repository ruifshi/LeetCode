#include "stdafx.h"
#include "FirstUniqueNumber.h"

#include <vector>

using namespace std;

//unordered_map<int, list<int>::iterator> map;
//list<int> uniques;

//use map to keep track of unique numbers that exist
//use linked list to keep order of unique number
FirstUnique::FirstUnique(vector<int>& nums) {
  for (int i = 0; i < nums.size(); i++) {
    add(nums[i]);
  }
}

int FirstUnique::showFirstUnique() {
  return uniques.empty() ? -1 : uniques.front();
}

void FirstUnique::add(int value) {
  // if number is found, then it's no longer unique
  // remove from list and set map to list.end() to signify this number is not unique anymore
  if (map.find(value) != map.end()) {
    if (map[value] != uniques.end()) {
      uniques.erase(map[value]);
      map[value] = uniques.end();
    }
  }
  else{
    uniques.push_back(value);
    map[value] = --uniques.end();
  }

  return;
}