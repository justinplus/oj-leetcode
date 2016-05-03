#include <iostream>
#include <algorithm>
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
    // by counting length
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      int s_a = 0, s_b = 0;
      ListNode *nd;

      for(nd = headA; nd; nd = nd->next) ++s_a;
      for(nd = headB; nd; nd = nd->next) ++s_b;

      if( s_a < s_b ) swap( headA , headB );

      for( int i = 0; i < abs(s_a - s_b); ++i ) headA = headA->next;

      for( ; headA && headB; headA = headA->next, headB = headB->next )
        if( headA == headB )
          return headA;

      return nullptr;
    }

    // NODE: impressive
    // by append lists logically
    ListNode *getIntersectionNode_app(ListNode *headA, ListNode *headB) {
      ListNode * nd1 = headA, * nd2 = headB;

      while( nd1 != nd2 ) {
        nd1 = nd1 ? nd1->next : headB;
        nd2 = nd2 ? nd2->next : headA;
      }

      return nd1;
    }
};

int main() {
  ListNode *a = new ListNode(3);
  a->next = new ListNode(3);
  ListNode *b = new ListNode(1);

  ListNode *com = new ListNode(2);

  a->next->next = com;
  b->next = com;

  Solution s;
  cout<< (s.getIntersectionNode(a, b) == com)<<endl;
  return 0;
}
