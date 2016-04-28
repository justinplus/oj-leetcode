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
    // merge 1 list into another list - 8ms
    ListNode* mergeTwoLists_2pts(ListNode* l1, ListNode* l2) {
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
        }

        l1 = l1->next;
      }

      if( !l1->next ) l1->next = l2;

      return l.next;
    }

    // merge 2 lists into one new list - 12ms
    ListNode* mergeTwoLists_3pts(ListNode *l1, ListNode *l2) {
      ListNode fake(0), *l = &fake;
      while( l1 && l2 ) {
        if( l1->val > l2->val ) {
          l->next = l2;
          l2 = l2->next;
        } else {
          l->next = l1;
          l1 = l1->next;
        }
        l = l->next;
      }

      if( !l1 ) l1 = l2;
      l->next = l1;

      return fake.next;
    }

    // using pointer of pointer - 12ms
    ListNode* mergeTwoLists_pp(ListNode *l1, ListNode *l2 ) {
      ListNode ** npp = &l1;

      for(; (*npp) && l2; npp = &((*npp)->next) )
        if( (*npp)->val > l2->val ) {
          ListNode *tmp = *npp;
          *npp = l2;
          l2 = l2->next;
          (*npp)->next = tmp;
        }

      // NOTE:
      if( l2 ) *npp = l2;
      return l1;
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
  // inspect( s.mergeTwoLists_2pts(l1, l2) );
  // inspect( s.mergeTwoLists_3pts(l1, l2) );
  inspect( s.mergeTwoLists_pp(l1, l2) );
  return 0;
}
