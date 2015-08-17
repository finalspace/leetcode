// Source : https://leetcode.com/problems/jump-game/
// Author : SiyuanXu
// Date   : 2015-08-12

/********************************************************************************** 
* 
* Given an array of non-negative integers, you are initially positioned at the first index of the array.
* 
* Each element in the array represents your maximum jump length at that position. 
* 
* Determine if you are able to reach the last index.
* 
* For example:
* A = [2,3,1,1,4], return true.
* 
* A = [3,2,1,0,4], return false.
* 
*               
**********************************************************************************/

//greedy
//16ms(best)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxL = 0;
		for(int i = 0; i<=maxL && i <nums.size(); i++){
			maxL = max(maxL, i + nums[i]);
		}
		return maxL >= nums.size() - 1;
    }
};
