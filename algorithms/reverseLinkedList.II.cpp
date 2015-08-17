// Source : https://leetcode.com/problems/reverse-linked-list-ii/
// Author : Siyuan Xu
// Date   : 2015-08-14

/********************************************************************************** 
* 
* Reverse a linked list from position m to n. Do it in-place and in one-pass.
* 
* For example:
* Given 1->2->3->4->5->NULL, m = 2 and n = 4,
* 
* return 1->4->3->2->5->NULL.
* 
* Note:
* Given m, n satisfy the following condition:
* 1 ≤ m ≤ n ≤ length of list.
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
 
 //dummy head
 //4ms(very good)
class Solution1 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode *h = dummy, *it, *rest, *front;
		for (int i = 0; i < m - 1; i++) {
			h = h->next;
		}
		front = h->next;
		it = h->next->next;
		for (int i = 0; i < n - m; i++) {
			rest = it->next;
			it->next = h->next;
			h->next = it;
			it = rest;
		}
		front->next = it;
		return dummy->next;
    }
};

//no dummy head
//4ms(best)
class Solution2 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode **front = &head, *it = head;
		for (int i = 0; i < m - 1; i++) front = &((*front)->next);
		it = (*front)->next;
		(*front)->next = new ListNode(0);
		ListNode** tail = &((*front)->next);
		for (int i = 0; i < n - m; i++) {
			ListNode* rest = it->next;
			it->next = *front;
			(*front) = it;
			it = rest;
		}
		*tail = it;
		return head;
    }
};
