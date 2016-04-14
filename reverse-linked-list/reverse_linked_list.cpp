/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if( head == NULL ) return head;

    	ListNode * pre = NULL;
    	ListNode * next = head->next;

    	while( true ){
    		head->next = pre;
    		if( next == NULL ) break;
    		pre = head;
    		head = next;
    		next = next->next;
    	}
    	return head;
    }

    ListNode * reverseList_concise( ListNode *head) {
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
