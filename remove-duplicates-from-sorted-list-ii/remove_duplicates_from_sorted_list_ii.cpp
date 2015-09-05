#include <iostream>
#include <vector>
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
    ListNode* deleteDuplicates(ListNode* head) {
      if(!head) return head;
      ListNode dummy(0), *p = &dummy; // use dummy node
      p->next = head;

      while( head->next ) {
        if(head->val != head->next->val) {
          if(p->next->next != head->next) {
            p->next = head->next;
          } else {
            p = p->next;
          }
        }
        head = head->next;
      }
      if(p->next->next) p->next = nullptr;
      
      return dummy.next;
    }
};

void inspect( const ListNode* l ) {
  while(l) { 
    cout<<l->val<<' ';
    l = l->next;
  }
  cout<<endl;
}

int main() {
  vector<int> v = {1, 1, 1 };
  ListNode head = ListNode(0), *h = &head;
  for(int n : v) {
    h->next = new ListNode(n);
    h = h->next;
  }
  h = head.next;

  Solution s;
  inspect(h);
  inspect(s.deleteDuplicates(h));
  return 0;
}
