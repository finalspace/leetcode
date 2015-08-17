// Source : https://leetcode.com/problems/add-two-numbers/
// Author : Siyuan Xu
// Date   : 2015-07-22

/********************************************************************************** 
* 
* There are two sorted arrays A and B of size m and n respectively. 
* Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*               
**********************************************************************************/
//44ms
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *root = new ListNode(0);
        ListNode *p = root;
		int c = 0;
		int d1 = 0;
		int d2 = 0;
		while(l1 || l2 || c){
			if(l1){
				d1 = l1->val;
				l1 = l1->next;
			}else{
				d1 = 0;
			}
			if(l2){
				d2 = l2->val;
				l2 = l2->next;
			}else{
				d2 = 0;
			}
			ListNode *digit = new ListNode((d1+d2+c)%10);
			p->next = digit;
			p = p->next;
			c = (d1+d2+c)/10;
		}
		return root->next;
        
    }
};


//40ms
class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *root = new ListNode(0);
		ListNode *p = root;
		int c = 0;
		while(l1 || l2 || c){
			if(l1) c += l1->val, l1 = l1->next;
			if(l2) c += l2->val, l2 = l2->next;
			ListNode *digit = new ListNode(c%10);
			p->next = digit;
			p = p->next;
			c = c/10;
		}
		return root->next;
        
    }
};
