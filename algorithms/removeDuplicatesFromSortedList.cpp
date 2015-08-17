// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Author : Siyuan Xu
// Date   : 2015-08-13

/********************************************************************************** 
* 
* Given a sorted linked list, delete all duplicates such that each element appear only once.
* 
* For example,
* Given 1->1->2, return 1->2.
* Given 1->1->2->3->3, return 1->2->3.
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
 
 //recursive
 //16ms(good)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        return (head && (head->next = deleteDuplicates(head->next)) && head->val == head->next->val) ? head->next : head;
    }
};

//12ms(best)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
		ListNode *p = head;
		while (p->next) {
			if (p->next->val == p->val) p->next = p->next->next;
			else p = p->next;
		}
		return head;
    }
};
