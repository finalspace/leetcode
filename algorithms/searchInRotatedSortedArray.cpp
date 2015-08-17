// Source : https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author : Siyuan Xu
// Date   : 2015-08-06

/********************************************************************************** 
* 
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
* 
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
* 
* You are given a target value to search. If found in the array return its index, otherwise return -1.
* 
* You may assume no duplicate exists in the array.
*               
**********************************************************************************/

//binary search
//4ms(best)
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty()) return -1;
		int l = 0, r = nums.size() -1;
		int m = 0;
		while (l < r) {
			m = (l + r) / 2;
			if (nums[m] < nums[l]) {
				if ((nums[m] < target) && (target <= nums[r]))
					l = m + 1;
				else r = m;
			}
			else {
				if ((nums[l] <= target) && (target <= nums[m]))
					r = m;
				else l = m + 1;
			}
		}
		return (nums[l] == target) ? l : -1;
	}
};

//binary search
//recursive
//4ms
class Solution2 {
public:
    int bSearch(vector<int> &nums, int l, int r, int target) {
		if (l == r) {
			return (nums[l] == target) ? l : -1;
		}
		int m = (l + r) / 2;
		if (nums[m] < nums[l]) {
			if ((nums[m] < target) && (target <= nums[r]))
				return bSearch(nums, m+1, r, target);
			else return bSearch(nums, l, m, target);
		}
		else {
			if ((nums[l] <= target) && (target <= nums[m]))
				return bSearch(nums, l, m, target);
			else return bSearch(nums, m+1, r, target);
		}
	}
	int search(vector<int>& nums, int target) {
		if (nums.empty()) return -1;
		return bSearch(nums, 0, nums.size()-1, target);
	}
};
