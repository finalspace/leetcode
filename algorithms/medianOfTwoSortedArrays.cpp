// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author : Siyuan Xu
// Date   : 2015-07-22

/********************************************************************************** 
* 
* There are two sorted arrays A and B of size m and n respectively. 
* Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*               
**********************************************************************************/

//44ms
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     int m,n,k;
    m = nums1.size();
    n = nums2.size();
    auto beg1 = nums1.begin(),beg2 = nums2.begin();
    k = (m+n)>>1;
    if((m+n) & 0x1)
        return find_kth(nums1,beg1,nums2,beg2,k+1);
    else 
        return (find_kth(nums1,beg1,nums2,beg2,k) + find_kth(nums1,beg1,nums2,beg2,k+1))/2.0;

        
    }
    private:
double find_kth(vector<int>& nums1,vector<int>::iterator beg1,vector<int>& nums2,vector<int>::iterator beg2,int k)
{
    int m = nums1.end() - beg1,n = nums2.end() - beg2;
    if(m>n) 
        return find_kth(nums2,beg2,nums1,beg1,k);
    if(m==0) return *(beg2+k-1);
    if(k==1) return min(*beg1,*beg2);
    int m1 = min(k/2,m),m2 = k-m1;
    if(*(beg1+m1-1)<*(beg2+m2-1))
        return find_kth(nums1,beg1+m1,nums2,beg2,k-m1);
    else if(*(beg1+m1-1)>*(beg2+m2-1))
        return find_kth(nums1,beg1,nums2,beg2+m2,k-m2);
    else
        return *(beg1+m1-1);
}
        
};
