#include "stdafx.h"
#include "ImplementQueueUsingStacks.h"

/*
I have one input stack, onto which I push the incoming elements, and one output stack, from which I peek/pop. 
I move elements from input stack to output stack when needed, i.e., when I need to peek/pop but the output stack is empty. 
When that happens, I move all elements from input to output stack, thereby reversing the order so it's the correct order for peek/pop.

The loop in peek does the moving from input to output stack. Each element only ever gets moved like that once, though, 
and only after we already spent time pushing it, so the overall amortized cost for each operation is O(1).
*/
/** Initialize your data structure here. */
MyQueue::MyQueue() {

}

/** Push element x to the back of queue. */
void MyQueue::push(int x) {
  input.push(x);
}

/** Removes the element from in front of queue and returns that element. */
int MyQueue::pop() {
  int v = peek();
  output.pop();
  return v;
}

/** Get the front element. */
int MyQueue::peek() {
  if (output.empty())
    while (input.size())
      output.push(input.top()), input.pop();
  return output.top();
}

/** Returns whether the queue is empty. */
bool MyQueue::empty() {
  return input.empty() && output.empty();
}