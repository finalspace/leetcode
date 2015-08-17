// Source : https://leetcode.com/problems/search-insert-position/
// Author : Siyuan Xu
// Date   : 2015-08-06

/********************************************************************************** 
* 
* Given a sorted array and a target value, return the index if the target is found. 
* If not, return the index where it would be if it were inserted in order.
* 
* You may assume no duplicates in the array.
* 
* Here are few examples.
* [1,3,5,6], 5 → 2
* [1,3,5,6], 2 → 1
* [1,3,5,6], 7 → 4
* [1,3,5,6], 0 → 0
* 
*               
**********************************************************************************/

//binary search
//8ms(best)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
		int l = 0, r = nums.size() - 1;
		int m = 0;
		while (l < r) {
			m = (l + r) / 2;
			if (target <= nums[m]) r = m;
			else l = m + 1;
		}
		return nums[l] >= target ? l : l + 1;
    }
};
