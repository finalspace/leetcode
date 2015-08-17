// Source : https://leetcode.com/problems/partition-list/
// Author : Siyuan Xu
// Date   : 2015-08-13

/********************************************************************************** 
* 
* Given a linked list and a value x, partition it such that all nodes less than x come 
* before nodes greater than or equal to x.
* 
* You should preserve the original relative order of the nodes in each of the two partitions.
* 
* For example,
* Given 1->4->3->2->5->2 and x = 3,
* return 1->2->2->4->3->5.
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
 
//8ms(best)
class Solution1 {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode node1(0), node2(0);
		ListNode *p1 = &node1, *p2 = &node2;
		while (head) {
			if (head->val < x) {
				p1 = p1->next = head;
			}
			else {
				p2 = p2->next = head;
			}
			head = head->next;
		}
		p2->next = NULL;
		p1->next = node2.next;
		return node1.next;
    }
};


//8ms(best)
class Solution2 {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *pL = NULL, *pR = NULL, *pLH = NULL, *pRH = NULL, *p = head;
		while (p) {
			if (p->val < x) {
				if (!pL) { pLH = pL = p; }
				else { pL->next = p; pL = p; }
			}
			else {
				if (!pR) { pRH = pR = p; }
				else { pR->next = p; pR = p; }
			}
			p = p->next;
		}
		if (pR) { pR->next = NULL; }
		if (!pLH) return pRH;
		pL->next = pRH;
		return pLH;
    }
};
