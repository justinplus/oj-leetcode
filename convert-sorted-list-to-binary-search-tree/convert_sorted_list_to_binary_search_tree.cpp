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

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    TreeNode* sortedListToBST(ListNode* head) {
      return sortedListToBST(head, nullptr);
    }

    TreeNode* sortedListToBST(ListNode* head, ListNode* tail) {
      if( head == tail ) return nullptr;

      ListNode *fast = head, *slow = head;

      while(fast->next != tail && fast->next->next != tail) {
        fast = fast->next->next;
        slow = slow->next;
      }

      TreeNode* r = new TreeNode(slow->val);
      r->left = sortedListToBST(head, slow);
      r->right = sortedListToBST(slow->next, tail);

      return r;
    }

};

int main() {
  return 0;
}
