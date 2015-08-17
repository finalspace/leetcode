// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Author : Siyuan Xu
// Date   : 2015-08-12

/********************************************************************************** 
* 
* Follow up for "Remove Duplicates":
* What if duplicates are allowed at most twice?
* 
* For example,
* Given sorted array A = [1,1,1,2,2,3],
* 
* Your function should return length = 5, and A is now [1,1,2,2,3].
* 
*               
**********************************************************************************/

//16ms(best)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
		int k = 1;
		for (int i = 2; i < nums.size(); i++) {
			if (nums[i] != nums[k - 1]) nums[++k] = nums[i];
		}
		return k + 1;
    }
};

//20ms(good)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int offset = 0, counts = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == nums[i - 1]) {
				counts++;
				if (counts > 1) offset++;
			}
			else {
				counts = 0;
			}
			nums[i - offset] = nums[i];
		}
		return nums.size() - offset;
    }
};
