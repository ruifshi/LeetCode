#include "stdafx.h"
#include "DesignHashMap.h"

//vector<int> hashMap;

/** Initialize your data structure here. */
MyHashMap::MyHashMap() {

}

/** value will always be non-negative. */
void MyHashMap::put(int key, int value) {
  if (key >= hashMap.size()) {
    for (int i = hashMap.size();i <= key;i++) hashMap.push_back(-1);
  }
  hashMap[key] = value;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int MyHashMap::get(int key) {
  if (key >= hashMap.size()) return -1;
  return hashMap[key];
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void MyHashMap::remove(int key) {
  if (key >= hashMap.size()) return;
  hashMap[key] = -1;
}

/*
#define SIZE 20

struct DataItem {
   int data;
   int key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key) {
   return key % SIZE;
}

struct DataItem *search(int key) {
   //get the hash
   int hashIndex = hashCode(key);

   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {

      if(hashArray[hashIndex]->key == key)
         return hashArray[hashIndex];

      //go to next cell
      ++hashIndex;

      //wrap around the table
      hashIndex %= SIZE;
   }

   return NULL;
}

void insert(int key,int data) {

   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data = data;
   item->key = key;

   //get the hash
   int hashIndex = hashCode(key);

   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      //go to next cell
      ++hashIndex;

      //wrap around the table
      hashIndex %= SIZE;
   }

   hashArray[hashIndex] = item;
}

struct DataItem* delete(struct DataItem* item) {
   int key = item->key;

   //get the hash
   int hashIndex = hashCode(key);

   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {

      if(hashArray[hashIndex]->key == key) {
         struct DataItem* temp = hashArray[hashIndex];

         //assign a dummy item at deleted position
         hashArray[hashIndex] = dummyItem;
         return temp;
      }

      //go to next cell
      ++hashIndex;

      //wrap around the table
      hashIndex %= SIZE;
   }

   return NULL;
}
*/