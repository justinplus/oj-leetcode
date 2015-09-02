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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int carry = 0;
      ListNode sum(0); 
      ListNode *cur = &sum;

      while( l1 && l2) {
        cur->next = new ListNode( (l1->val + l2->val + carry)%10 );
        carry = (l1->val + l2->val + carry)/10; // Attention should add carry!!
        cur = cur->next;
        l1 = l1->next;
        l2 = l2->next;
      }
      l1 = l1 ? l1 : l2;
      while(l1) {
        cur->next = new ListNode( (l1->val + carry)%10 );
        carry = (l1->val + carry)/10;
        cur = cur->next;
        l1 = l1->next;
      }
      if(carry){
        cur->next = new ListNode(carry);
      }
      return sum.next;
    }
};

void inspect( const ListNode * l ) {
  while(l) {
    cout<<l->val<< ' ';
    l=l->next;
  }
  cout<<endl;
}

int main(){
  ListNode * l1 = new ListNode(3);
  l1->next = new ListNode(7);

  ListNode * l2 = new ListNode(9);
  l2->next = new ListNode(2);

  Solution s;

  inspect(s.addTwoNumbers(l1, l2));

  return 0;
}

