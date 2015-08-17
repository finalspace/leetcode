// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Author : Siyuan Xu
// Date   : 2015-08-13

/********************************************************************************** 
* 
* Given a sorted linked list, delete all nodes that have duplicate numbers, 
* leaving only distinct numbers from the original list.
* 
* For example,
* Given 1->2->3->3->4->4->5, return 1->2->5.
* Given 1->1->1->2->3, return 2->3.
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
 
//no dummy head
//8ms(best)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode **it = &head;
		while(*it){
			if ((*it)->next && (*it)->val == (*it)->next->val){
				ListNode* p = (*it)->next;
				while(p->next && p->next->val == p->val)
					p = p->next;
				*it = p->next;
			}
			else{
				it = &((*it)->next);
			}
		}
		return head;
    }
};


//normal dummy head
//8ms(best)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        ListNode **it = &head, **front = NULL;
		int pre = head->val - 1;
		bool dup = false;
		while (*it) {
			if ((*it)->val == pre){
				dup = true;
			}
			else{
				if (front && dup)
					*front = *it;
				else front = it;
				pre = (*it)->val;
				dup = false;
			}
			it = &((*it)->next);
		}
		if (dup) 
			*front = NULL;
		return head;
    }
};
