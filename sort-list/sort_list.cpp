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
    ListNode* sortList(ListNode* head) {
      if(!head || !head->next) return head;
      ListNode *slow = head;
      ListNode *fast = head->next;

      while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
      }

      ListNode *mid = slow->next;
      slow->next = nullptr;

      return merge(sortList(head), sortList(mid));
    } // TODO: use iterative one or improve it in other ways

    ListNode * merge(ListNode *l1, ListNode *l2) {
      ListNode l(0); // dummp node
      l.next = l1; // Tip: linked list with header simplify processing!!
      l1 = &l;
      ListNode *tmp = nullptr;

      while( l1->next && l2 ) {
        if( l1->next->val > l2->val ) {
          tmp = l2->next;
          l2->next = l1->next;
          l1->next = l2;
          l2 = tmp;
        } else { 
          l1 = l1->next;
        }
      }

      if( !l1->next ) l1->next = l2;
      
      return l.next;
    }
};

void inspect(const ListNode * l) {
  while(l) {
    cout<<l->val<<' ';
    l = l->next;
  }
  cout<<endl;
}

int main() {
  ListNode * l = new ListNode(3);
  l->next = new ListNode(1);
  l->next->next = new ListNode(4);
  
  Solution s;
  inspect(s.sortList(l));
  return 0;
}
