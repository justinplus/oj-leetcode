#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// Reverse the link or use fast and slow ptr!!!
class Solution {
  public:
    bool hasCycle(ListNode *head) {
      ListNode *fast = head;
      ListNode *slow = head;

      while(fast) {
        if(fast->next)
          fast = fast->next->next;
        else
          return false;

        slow = slow->next;
        if(slow == fast) return true;
      }
      return false;

    }
};
