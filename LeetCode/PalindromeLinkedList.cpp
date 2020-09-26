#include "stdafx.h"
#include "PalindromeLinkedList.h"

ListNode* reverseList2(ListNode* head) {
  ListNode *current = head, *prev = nullptr, *next = nullptr;

  while (current) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  head = prev;

  return head;
}

// O(1) space
bool Solution::isPalindrome(ListNode* head) {
  if (head == nullptr || head->next == nullptr)
    return true;

  // find middle of list
  ListNode* slow = head;
  ListNode* fast = head;

  while (fast->next != NULL && fast->next->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  // reverse 2nd half and compare
  slow->next = reverseList2(slow->next);
  slow = slow->next;

  while (slow != NULL) {
    if (head->val != slow->val)
      // can reverse back 2nd half if list needs to be preserved
      return false;

    head = head->next;
    slow = slow->next;
  }

  // can reverse back 2nd half if list needs to be preserved
  return true;
}

/* O(n) space
class Solution {
    public boolean isPalindrome(ListNode head) {
        List<Integer> vals = new ArrayList<>();

        // Convert LinkedList into ArrayList.
        ListNode currentNode = head;
        while (currentNode != null) {
            vals.add(currentNode.val);
            currentNode = currentNode.next;
        }

        // Use two-pointer technique to check for palindrome.
        int front = 0;
        int back = vals.size() - 1;
        while (front < back) {
            // Note that we must use ! .equals instead of !=
            // because we are comparing Integer, not int.
            if (!vals.get(front).equals(vals.get(back))) {
                return false;
            }
            front++;
            back--;
        }
        return true;
    }
}
*/