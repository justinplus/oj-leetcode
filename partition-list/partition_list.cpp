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

class Solution {
  public:
    ListNode* partition(ListNode* head, int x) {
      ListNode dummy(0), *dh = &dummy, *cur, *tmp;
      dh->next = head;

      while( dh->next && dh->next->val < x ) dh = dh->next;

      cur = dh;

      while( cur->next ) {
        if(cur->next->val < x && dh != cur) {
          tmp = dh->next;
          dh->next = cur->next;
          cur->next = cur->next->next;
          dh = dh->next;
          dh->next = tmp;
        } else {
          cur = cur->next;
        }
      }

      return dummy.next;
    }

};

int main() {
  return 0;
}
