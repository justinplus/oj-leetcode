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

// TODO: Any concise way?
class Solution {
  public:
    ListNode* rotateRight(ListNode* head, int k) {
      if(!head || k <= 0) return head;

      ListNode *end = head;
      int len = 1;
      for(; end->next; len++, end = end->next);
      
      k %= len;
      if(k == 0) return head;
      ListNode *bp = head;
      for(int i = 0; i < len-k-1; i++, bp = bp->next);

      end->next = head;
      head = bp->next;
      bp->next = nullptr;
      return head;
    }
};

void inspect( ListNode *head) {
  while(head){
    cout<<head->val<<' ';
    head = head->next;
  }
  cout<<endl;
}

int main() {
  Solution s;
  ListNode *h = nullptr;
  inspect(h);
  inspect(s.rotateRight(h, 1));
  h = new ListNode(1);
  inspect(h);
  inspect(s.rotateRight(h, 10));
  h->next = new ListNode(2);
  h->next->next = new ListNode(3);
  h->next->next->next = new ListNode(4);
  h->next->next->next->next = new ListNode(5);
  inspect(h);
  inspect(s.rotateRight(h, 7));

  return 0;
}
