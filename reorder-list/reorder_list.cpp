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
    void reorderList(ListNode* head) {
      if( !head ) return; // when length is 0

      ListNode *slow = head, *fast = head;

      while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
      }

      if(!slow->next) return; // when length is 1

      ListNode *pre = nullptr, *nd = slow->next, *succ;
      slow->next = nullptr;

      while( nd ) {
        succ = nd->next;
        nd->next = pre;
        pre = nd;
        nd = succ;
      }

      ListNode *l1 = head, *l2 = pre;
      ListNode *succ1, *succ2;
      while( l1 && l2 ) {
        succ1 = l1->next;
        succ2 = l2->next;
        l1->next = l2;
        l2->next = succ1;
        l1 = succ1;
        l2 = succ2;
      }

    }
};

int main() {

  ListNode *l = new ListNode(1);
  l->next = new ListNode(2);
  l->next->next = new ListNode(3);
  l->next->next->next = new ListNode(4);
  l->next->next->next->next = new ListNode(5);

  Solution s;
  s.reorderList(l);
  
  for(; l; l = l->next) cout<<l->val<<' ';
  cout<<endl;

  return 0;
}
