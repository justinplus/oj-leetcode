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
    // TODO: implement without fake nodes
    ListNode* oddEvenList(ListNode* head) {
      if( !head ) return nullptr;

      ListNode odd(0), even(0);
      ListNode *oddp = &odd, *evenp = &even;

      while( head ) {
        oddp->next = head;
        oddp = oddp->next;
        head = head->next;

        if(head){
          evenp->next = head;
          evenp = evenp->next;
          head = head->next;
        }
      }

      evenp->next = nullptr; // NOTE
      oddp->next = even.next;

      return odd.next;
    }
};

int main() {
  return 0;
}
