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
};