// Source : https://leetcode.com/problems/next-permutation/
// Author : Siyuan Xu
// Date   : 2015-08-05

/********************************************************************************** 
* 
* Implement next permutation, which rearranges numbers into the lexicographically next 
* greater permutation of numbers.
* 
* If such arrangement is not possible, it must rearrange it as the lowest possible order 
* (ie, sorted in ascending order).
* 
* The replacement must be in-place, do not allocate extra memory.
* 
* Here are some examples. Inputs are in the left-hand column and its corresponding outputs 
* are in the right-hand column.
*
*   1,2,3 → 1,3,2
*   3,2,1 → 1,2,3
*   1,1,5 → 1,5,1
*               
**********************************************************************************/

//cheat
//12ms
class Solution1 {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

//find the decending from back, then next permutation happen after this position
//from back, find the first number that is bigger than the current one, swap
//then sort the rest
//here reverse is the same result, since the rest is all decending
//12ms(best)
class Solution2 {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) return;
		int d1 = nums[nums.size() - 1];
		int p1 = nums.size() - 1;
		for (int i = nums.size() - 2; i >= 0; i--) {
			if (nums[i] < nums[i + 1]) {
				d1 = nums[i];
				p1 = i;
				break;
			}
		}
		if (p1 == nums.size() - 1) {
			reverse(nums.begin(), nums.end());
			return;
		}
		for (int i = nums.size() - 1; i >= 0; i--) {
			if (nums[i] > d1) {
				swap(nums[p1], nums[i]);
				reverse(nums.begin() + p1 + 1, nums.end());
				break;
			}
		}
    }
};

//fancy
//12ms(best)
class Solution3 {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) return;
		vector<int>::reverse_iterator p1 = is_sorted_until(nums.rbegin(), nums.rend());
		if (p1 == nums.rend()) {
			reverse(nums.begin(), nums.end());
			return;
		}
		swap(*p1, *upper_bound(nums.rbegin(), p1, *p1));
		reverse(nums.rbegin(), p1);
    }
};

//more concise
//12ms(best)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) return;
		vector<int>::reverse_iterator p1 = is_sorted_until(nums.rbegin(), nums.rend());
		if (p1 != nums.rend()) {
			swap(*p1, *upper_bound(nums.rbegin(), p1, *p1));
		}
		reverse(nums.rbegin(), p1);
    }
};
