// Source : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Author : Siyuan Xu
// Date   : 2015-08-12

/********************************************************************************** 
* 
* Follow up for "Search in Rotated Sorted Array":
* What if duplicates are allowed?
* 
* Would this affect the run-time complexity? How and why?
* 
* Write a function to determine if a given target is in the array.
*               
**********************************************************************************/


//8ms
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
		int l = 0, r = nums.size() - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (nums[m] == target) return true;
			if (nums[l] < nums[m]){
				if (nums[l] <= target && target < nums[m]) r = m - 1;
				else l = m + 1;
			}
			else if (nums[l] > nums[m]) {
				if (nums[m] < target && target <= nums[r]) l = m + 1;
				else r = m - 1;
			}
			else l++;
		}
		return false;
    }
};

