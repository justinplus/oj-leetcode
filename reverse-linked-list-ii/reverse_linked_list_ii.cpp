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
    // condition: 1 ≤ m ≤ n ≤ length of list
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      if( m == n ) return head;

      ListNode fake(0); fake.next = head;

      int i = 1;
      ListNode *begin = &fake;
      for( ; i < m; ++i ) begin = begin->next;
      ListNode *end = begin;
      for( ; i <= n; ++i ) end = end->next;

      begin->next = reverseList( begin->next, end->next, end->next);

      return fake.next;
    }

    ListNode * reverseList( ListNode *head, ListNode *pre_h, ListNode *limit) {
      ListNode *pre = pre_h, *tmp;
      while( head != limit) {
        tmp = head->next;
        head->next = pre;
        pre = head;
        head = tmp;
      }
      return pre;
    }
};

int main() {
  return 0;
}
