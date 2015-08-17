// Source : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author : Siyuan Xu
// Date   : 2015-08-02

/********************************************************************************** 
* 
* Given a linked list, remove the nth node from the end of list and return its head.
* 
* For example,
* 
*    Given linked list: 1->2->3->4->5, and n = 2.
* 
*    After removing the second node from the end, the linked list becomes 1->2->3->5.
* 
* Note:
* Given n will always be valid.
* Try to do this in one pass.
* 
*               
**********************************************************************************/

//front back node with n segment, move both until back reaches the end
//4ms
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* preHead = new ListNode(0);
		preHead -> next = head;
		ListNode* node1 = preHead;
		ListNode* node2 = preHead;
		while (n > 0) {
			node2 = node2->next;
			n--;
		}
		while (node2->next) {
			node1 = node1->next;
			node2 = node2->next;
		}
		node1->next = node1->next->next;
		return preHead->next;
    }
};

//8ms
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* preHead = new ListNode(0);
		preHead -> next = head;
		ListNode* node1 = preHead;
		ListNode* node2 = preHead;
		while (n > 0) {
			node2 = node2->next;
			n--;
		}
		while (node2->next) {
			node1 = node1->next;
			node2 = node2->next;
		}
		ListNode* toDelete = node1->next;
		//node1->next = node1->next->next;
		ListNode** a1 = &(node1->next);
		*a1 = ((*a1)->next);
		delete toDelete;
		return preHead->next;
    }
};
