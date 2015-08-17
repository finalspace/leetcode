// Source : https://leetcode.com/problems/swap-nodes-in-pairs/
// Author : Siyuan Xu
// Date   : 2015-08-04

/********************************************************************************** 
* 
* Given a linked list, swap every two adjacent nodes and return its head.
* 
* For example,
* Given 1->2->3->4, you should return the list as 2->1->4->3.
* 
* Your algorithm should use only constant space. You may not modify the values in the list, 
* only nodes itself can be changed.
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
 
//normal pointer
//4ms
class Solution1 {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return head;
        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};

//second level pointer
//4ms
class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode** it = &head;
		ListNode* temp;
		while(*it && (*it)->next){
			temp = (*it)->next;
			(*it)->next = (*it)->next->next;
			temp->next = *it;
			*it = temp;
			it = &((*it)->next->next);
		}
		return head;
        
    }
};
