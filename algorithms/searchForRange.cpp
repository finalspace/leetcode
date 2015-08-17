// Source : https://leetcode.com/problems/search-for-a-range/
// Author : Siyuan Xu
// Date   : 2015-08-06

/********************************************************************************** 
* 
* Given a sorted array of integers, find the starting and ending position of a given target value.
* 
* Your algorithm's runtime complexity must be in the order of O(log n).
* 
* If the target is not found in the array, return [-1, -1].
* 
* For example,
* Given [5, 7, 7, 8, 8, 10] and target value 8,
* return [3, 4].
* 
*               
**********************************************************************************/

//binary search (straightforward)
//12ms
class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
		if (nums.empty()) return vector<int>(2, -1);
		int l = 0, r = nums.size() - 1;
		int m = 0;
		while (l < r) {
			int m = (l + r) / 2;
			if (target <= nums[m]) r = m;
			else if (target>nums[m]) l = m+1;
		}
		if (nums[l] != target) return vector<int>(2, -1);
		res.push_back(l);
		while (l+1 < nums.size() && nums[l+1] == target) {
			l++;
		}
		res.push_back(l);
		return res;
    }
};

//lib algorithm (concise)
//4ms
class Solution2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
		if (nums.empty()) return vector<int>(2, -1);
		auto l = lower_bound(nums.begin(), nums.end(), target);
		auto r = upper_bound(nums.begin(), nums.end(), target);
		if (l != nums.end() && *l == target) {
			res.push_back(distance(nums.begin(), l));
			res.push_back(distance(nums.begin(), r) - 1);
		}
		else { 
			res.push_back(-1);
			res.push_back(-1);
		};
		return res;
    }
};
