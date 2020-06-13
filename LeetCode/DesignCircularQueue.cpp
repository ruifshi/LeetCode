#include "stdafx.h"
#include "DesignCircularQueue.h"

/*
  vector<int> queue;
  int head;
  int count;
  int capacity;
*/

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue::MyCircularQueue(int k) {
  capacity = k;
  head = 0;
  count = 0;
  queue.resize(k);
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool MyCircularQueue::enQueue(int value) {
  if (count == capacity) return false;

  queue[(head + count) % capacity] = value;
  count++;

  return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool MyCircularQueue::deQueue() {
  if (count == 0) return false;

  head = (head + 1) % capacity;
  count--;

  return true;
}

/** Get the front item from the queue. */
int MyCircularQueue::Front() {
  if (count == 0) return -1;

  return queue[head];
}

/** Get the last item from the queue. */
int MyCircularQueue::Rear() {
  if (count == 0) return -1;
  int tail = (head + count - 1) % capacity;

  return queue[tail];
}

/** Checks whether the circular queue is empty or not. */
bool MyCircularQueue::isEmpty() {
  return count == 0;
}

/** Checks whether the circular queue is full or not. */
bool MyCircularQueue::isFull() {
  return count == capacity;
}


/**
class Node {
  public int value;
  public Node nextNode;

  public Node(int value) {
    this.value = value;
    this.nextNode = null;
  }
}

class MyCircularQueue {

  private Node head, tail;
  private int count;
  private int capacity;

  // Initialize your data structure here. Set the size of the queue to be k.
  public MyCircularQueue(int k) {
    this.capacity = k;
  }

  // Insert an element into the circular queue. Return true if the operation is successful.
  public boolean enQueue(int value) {
    if (this.count == this.capacity)
      return false;

    Node newNode = new Node(value);
    if (this.count == 0) {
      head = tail = newNode;
    }
    else {
      tail.nextNode = newNode;
      tail = newNode;
    }
    this.count += 1;
    return true;
  }

  // Delete an element from the circular queue. Return true if the operation is successful.
  public boolean deQueue() {
    if (this.count == 0)
      return false;
    this.head = this.head.nextNode;
    this.count -= 1;
    return true;
  }

  // Get the front item from the queue. 
  public int Front() {
    if (this.count == 0)
      return -1;
    else
      return this.head.value;
  }

  // Get the last item from the queue. 
  public int Rear() {
    if (this.count == 0)
      return -1;
    else
      return this.tail.value;
  }

  // Checks whether the circular queue is empty or not. 
  public boolean isEmpty() {
    return (this.count == 0);
  }

  // Checks whether the circular queue is full or not. 
  public boolean isFull() {
    return (this.count == this.capacity);
  }
}
*/