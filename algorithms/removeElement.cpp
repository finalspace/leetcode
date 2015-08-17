// Source : https://leetcode.com/problems/remove-element/
// Author : Siyuan Xu
// Date   : 2015-08-04

/********************************************************************************** 
* 
* Given an array and a value, remove all instances of that value in place and return the new length.
* 
* The order of elements can be changed. It doesn't matter what you leave beyond the new length.
* 
*               
**********************************************************************************/

//array trick
//4ms(best)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = nums.size();
		int count = 0;
		for(int i = 0; i < l; i++){
			if (nums[i] == val) count++;
			else nums[i-count] = nums[i];
		}
		return l-count;
        
    }
};
