#include <iostream>
#include <vector>
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
    bool isPalindrome(ListNode* head) {
      if( !head ) return true;

      ListNode *fast = head, *slow = head;
      while( fast->next && fast->next->next ) {
        fast = fast->next->next;
        slow = slow->next;
      }

      ListNode *rev = reverse(slow->next);
      slow->next = nullptr;

      while( rev && head ) {
        if(rev->val != head->val ) return false;
        rev = rev->next;
        head = head->next;
      }

      // TODO: restore

      return true;
    }

    ListNode * reverse( ListNode *head) {
      ListNode *pre = nullptr, *tmp;
      while( head ) {
        tmp = head->next;
        head->next = pre;
        pre = head;
        head = tmp;
      }
      return pre;
    }
};

int main() {
  Solution s;

  ListNode * h = new ListNode(2);
  h->next = new ListNode(3);
  h->next->next = new ListNode(4);

  ListNode *nh = s.reverse(nullptr);

  while(nh) {
    cout<<nh->val<<endl;
    nh = nh->next;
  }

  return 0;
}
