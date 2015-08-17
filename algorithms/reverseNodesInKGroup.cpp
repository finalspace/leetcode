// Source : https://oj.leetcode.com/problems/reverse-nodes-in-k-group/
// Author : Hao Chen
// Date   : 2014-07-05

/********************************************************************************** 
* 
* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
* 
* If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
* 
* You may not alter the values in the nodes, only nodes itself may be changed.
* 
* Only constant memory is allowed.
* 
* For example,
* Given this linked list: 1->2->3->4->5
* 
* For k = 2, you should return: 2->1->4->3->5
* 
* For k = 3, you should return: 3->2->1->4->5
* 
*               
**********************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //reverse every k nodes
 //one pass
 //28ms
class Solution {
public:
    ListNode* reverseList(ListNode* head){
		ListNode** it = &head;
		if((*it)->next){
			ListNode* tempHead = (*it)->next;
			ListNode* temp = reverseList((*it)->next);
			tempHead->next = *it;
			(*it)->next = NULL;
			*it = temp;
		}
		return head;
	}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode** secHead = &head;
		ListNode* secTail = NULL;
		ListNode** it = &head;
		ListNode* left;
		int m = k;
		while(*it){
			while(*it && m>0){
				m--;
				it = &((*it)->next);
			}
			if(m==0){
				left = *it;
				*it = NULL;
				secTail = *secHead;
				*secHead = reverseList(*secHead);
				secTail->next = left;
				secHead = &(secTail->next);
				it = secHead;
				m = k;
			}
		}
		return head;
        
    }
};
