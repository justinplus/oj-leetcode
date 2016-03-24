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
    // TODO: improve performance
    ListNode* insertionSortList(ListNode* head) {
      if(!head) return nullptr;

      ListNode dummy(0);
      ListNode *h = &dummy;
      h->next = head;
      head = head->next;
      h->next->next = nullptr;

      ListNode *pre, *nd;
      while( head ) {
        pre = h;
        nd = h->next;
        while( nd ) {
          if(head->val >= nd->val) {
            pre = nd;
            nd = nd->next;
          } else {
            break;
          }
        }
        pre->next = head;
        head = head->next;
        pre->next->next=nd;
      }

      return h->next;
    }
};

int main() {
  ListNode *l = new ListNode(5);
  l->next = new ListNode(3);
  l->next->next = new ListNode(2);
  l->next->next->next = new ListNode(1);
  l->next->next->next->next = new ListNode(4);

  Solution s;
  ListNode *l1 = s.insertionSortList(l);
  for(; l1; l1=l1->next) cout<<l1->val<<' ';
  cout<<endl;

  return 0;
}
