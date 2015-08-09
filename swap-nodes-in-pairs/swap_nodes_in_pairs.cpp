/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

#include <iostream>
using namespace std;

class Solution {
  public:
    ListNode* swapPairs(ListNode* head) {
      ListNode *fst = head;
      ListNode *pre = nullptr;
      if( fst ) {
        if( fst->next ){
          head = fst->next;
          fst->next = head->next;
          head->next = fst;
        }
        while( fst->next && fst->next->next ){
          pre = fst;
          fst = fst->next;
          pre->next = fst->next;
          fst->next = pre->next->next;
          pre->next->next = fst;
        }
      }
      return head;
    }
};

void inspect(ListNode *cur) {
  while(cur) {
    cout<<cur->val<<'\t';
    cur = cur->next;
  }
  cout<<endl;
}

int main(){
  Solution s;
  ListNode *h = new ListNode(1);
  inspect(h);
  inspect(s.swapPairs(h));
  h->next = new ListNode(2);
  inspect(h);
  h = s.swapPairs(h);
  inspect(h);
  h->next->next = new ListNode(3);
  h->next->next->next = new ListNode(4);
  inspect(h);
  h = s.swapPairs(h);
  inspect(h);
  h->next->next->next->next = new ListNode(5);
  h->next->next->next->next->next = new ListNode(6);
  inspect(h);
  h = s.swapPairs(h);
  inspect(h);
  inspect(s.swapPairs(nullptr));
  
  return 0;
}
