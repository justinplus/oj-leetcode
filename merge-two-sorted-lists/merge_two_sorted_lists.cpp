#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
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
  ListNode *l1 = new ListNode(3);
  l1->next = new ListNode(3);
  l1->next->next = new ListNode(8);
  ListNode *l2 = new ListNode(2);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(9);
  Solution s;
  inspect( s.mergeTwoLists(l1, l2) );
  return 0;
}
