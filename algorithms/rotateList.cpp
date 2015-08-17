
// Source : https://leetcode.com/problems/rotate-list/
// Author : Siyuan Xu
// Date   : 2015-08-10

/********************************************************************************** 
* 
* Given a list, rotate the list to the right by k places, where k is non-negative.
* 
* For example:
* Given 1->2->3->4->5->NULL and k = 2,
* return 4->5->1->2->3->NULL.
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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return 0;
		ListNode **newH = &head, **p = &head;
		int len = 0;
		while (*p) {
			p = &((*p)->next);
			len++;
		}
		*p = head;
		k %= len;
		for (int i = 0; i < len - k; i++) {
			newH = &((*newH)->next);
		}
		head = *newH;
		*newH = NULL;
		return head;
    }
};

//12ms(good)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return 0;
		ListNode **newH = &head, **p = &head;
		int len = 0;
		while (*p) {
			p = &((*p)->next);
			len++;
		}
		*p = head;
		k %= len;
		for (int i = 0; i < len - k; i++) {
			newH = &((*newH)->next);
		}
		head = *newH;
		*newH = NULL;
		return head;
    }
};

//16ms
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;

        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;

        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
};

//20ms
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return 0;
        ListNode **front = &head, **tail = front;
		ListNode *p = head;
		int len = 0;
		while (p) { p = p->next; len++; }
		k %= len;
		while (k-- > 0 && *tail) tail = &((*tail)->next);
		while (*tail) {
			front = &((*front)->next);
			tail = &((*tail)->next);
		}
		*tail = head;
		head = *front;
		*front = NULL;
		return head;
    }
};
