#include "stdafx.h"
#include "MaxStack.h"

/*
  stack<int> stk;
  stack<int> maxStk;
*/

/** initialize your data structure here. */
MaxStack::MaxStack() {

}

void MaxStack::push(int x) {
  int max = maxStk.empty() ? x : maxStk.top();
  maxStk.push(max > x ? max : x);
  stk.push(x);
}

int MaxStack::pop() {
  maxStk.pop();
  int val = stk.top();
  stk.pop();
  return val;
}

int MaxStack::top() {
  return stk.top();
}

int MaxStack::peekMax() {
  return maxStk.top();
}

int MaxStack::popMax() {
  int max = peekMax();
  stack<int> buffer;
  while (top() != max) buffer.push(pop());  // save values not max

  pop();  // pop max

  while (!buffer.empty()) { // add back
    push(buffer.top());
    buffer.pop();
  }

  return max;
}

/*
We use a doubly linked list for the data, and an ordered map that maps a value to a stack of entries in the list that have that value. 
To pop an, simply remove the newest element in the list, and pop the corresponding stack in the map. 
To popMax, pop the stack of entries that is mapped to by the max value, and remove the corresponding entry from the list.

C++ O(logN) for write ops, O(1) for reads
*/

/*
class MaxStack {
public:
    list<int> v;
    map<int, vector<list<int>::iterator>> mp;

    MaxStack() {
    }

    void push(int x) {
        v.insert(v.begin(),x);
        mp[x].push_back(v.begin());
    }

    int pop() {
        int x = *v.begin();
        mp[x].pop_back();
        if (mp[x].empty()) mp.erase(x);
        v.erase(v.begin());
        return x;
    }

    int top() {
        return *v.begin();
    }

    int peekMax() {
        return mp.rbegin()->first;
    }

    int popMax() {
        int x = mp.rbegin()->first;
        auto it = mp[x].back();
        mp[x].pop_back();
        if (mp[x].empty()) mp.erase(x);
        v.erase(it);
        return x;
    }
};
*/