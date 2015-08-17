// Source : https://leetcode.com/problems/first-missing-positive/
// Author : Siyuan Xu
// Date   : 2015-08-10

/********************************************************************************** 
* 
* Given an unsorted integer array, find the first missing positive integer.
* 
* For example,
* Given [1,2,0] return 3,
* and [3,4,-1,1] return 2.
* 
* Your algorithm should run in O(n) time and uses constant space.
* 
*               
**********************************************************************************/

//4ms(best)
class Solution1 {
//all items meet at lease once
//at most twice
//like grab all the items and place them into the correct place
//each number for the first time meet will be place into the correct place
//so all the numbers covered will be placed correctly
//the slot is missing is the what is missing
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
			while ((nums[i]>0) && (nums[i] <= nums.size()) && (nums[i] != nums[nums[i]-1]))
				swap(nums[i], nums[nums[i]-1]);
		}
		for(int i = 0; i< nums.size(); i++){
			if (nums[i] != i+1)
				return i+1;
		}
        return nums.size()+1;
    }
};
