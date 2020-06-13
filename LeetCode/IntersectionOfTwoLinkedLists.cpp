#include "stdafx.h"
#include "IntersectionOfTwoLinkedLists.h"

#include <unordered_set>

using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  if (headA == nullptr || headB == nullptr) return nullptr;

  unordered_set<ListNode *> mp;

  while (headA != nullptr) {
    mp.insert(headA);
    headA = headA->next;
  }

  while (headB != nullptr) {
    if (mp.find(headB) != mp.end()) {
      return headB;
    }
    headB = headB->next;
  }

  return nullptr;
}

/* 
// To see why the above trick would work, consider the following two lists: 
// A = {1,3,5,7,9,11} and B = {2,4,9,11}, which are intersected at node '9'. 
// Since B.length (=4) < A.length (=6), pBpB would reach the end of the merged list first, 
// because pBpB traverses exactly 2 nodes less than pApA does. By redirecting pBpB to head A, 
// and pApA to head B, we now ask pBpB to travel exactly 2 more nodes than pApA would. So in the second 
// iteration, they are guaranteed to reach the intersection node at the same time.
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
  ListNode *p1 = headA;
  ListNode *p2 = headB;

  if (p1 == NULL || p2 == NULL) return NULL;

  while (p1 != NULL && p2 != NULL && p1 != p2) {
    p1 = p1->next;
    p2 = p2->next;

    //
    // Any time they collide or reach end together without colliding 
    // then return any one of the pointers.
    //
    if (p1 == p2) return p1;

    //
    // If one of them reaches the end earlier then reuse it 
    // by moving it to the beginning of other list.
    // Once both of them go through reassigning, 
    // they will be equidistant from the collision point.
    //
    if (p1 == NULL) p1 = headB;
    if (p2 == NULL) p2 = headA;
  }

  return p1;
}
*/