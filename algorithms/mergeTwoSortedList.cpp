// Source : https://leetcode.com/problems/merge-two-sorted-lists/
// Author : Siyuan Xu
// Date   : 2015-08-03

/********************************************************************************** 
* 
* Merge two sorted linked lists and return it as a new list. The new list should be 
* made by splicing together the nodes of the first two lists.
*               
**********************************************************************************/

//12ms
class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL;
        ListNode** it = &head;
        while(l1 && l2){
            if (l1->val <= l2->val){
                *it = l1;
                l1 = l1->next;
            }
            else {
                *it = l2;
                l2 = l2->next;
            }
			it = &((*it)->next);
        }
        *it = l1? l1:l2;
        return head;
    }
};

//8ms
class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        ListNode* head = new ListNode(0);
        ListNode* rear = head;
        while(node1 && node2){
            if (node1->val <= node2->val){
                rear->next = node1;
                node1 = node1->next;
            }
            else {
                rear->next = node2;
                node2 = node2->next;
            }
            rear = rear->next;
        }
        rear->next = node1 ? node1 : node2;
        return head->next;
    }
};

//12ms
class Solution3 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        ListNode* head = new ListNode(0);
        ListNode* rear = head;
        while(node1 || node2){
            if (!node1){
                rear->next = node2;
				node2 = node2->next;
				rear = rear->next;
                continue;
            }
            if (!node2) {
                rear->next = node1;
				node1 = node1->next;
				rear = rear->next;
                continue;
            }
            if (node1->val <= node2->val){
                rear->next = node1;
                node1 = node1->next;
            }
            else {
                rear->next = node2;
                node2 = node2->next;
            }
            rear = rear->next;
        }
        return head->next;
    }
};
