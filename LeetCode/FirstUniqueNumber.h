#pragma once
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class FirstUnique {
private:
  unordered_map<int, list<int>::iterator> map;
  list<int> uniques;

public:
  FirstUnique(vector<int>& nums);

  int showFirstUnique();

  void add(int value);
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */