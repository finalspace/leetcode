// Source : https://leetcode.com/problems/merge-sorted-array/
// Author : Siyuan Xu
// Date   : 2015-08-14

/********************************************************************************** 
* 
* Given two sorted integer arrays A and B, merge B into A as one sorted array.
* 
* Note:
*   You may assume that A has enough space (size that is greater or equal to m + n) 
*   to hold additional elements from B. The number of elements initialized in A and B 
*   are m and n respectively.
*               
**********************************************************************************/


//4ms(best)
class Solution1 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
		while (p2 >= 0) {
			if (p1 < 0 || nums1[p1] <= nums2[p2])
				nums1[p1 + p2 + 1] = nums2[p2--];
			else nums1[p1 + p2 + 1] = nums1[p1--];
		}
    }
};


//4ms(best)
class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
		while (p1 >= 0 && p2 >= 0) {
			if (nums2[p2] >= nums1[p1]) {
				nums1[p1 + p2 + 1] = nums2[p2--];
			}
			else nums1[p1 + p2 + 1] = nums1[p1--];
		}
		while (p2 >= 0) {
			nums1[p2] = nums2[p2--];
		}
    }
};
