// Source : https://leetcode.com/problems/jump-game-ii/
// Author : Siyuan Xu
// Date   : 2014-08-10

/********************************************************************************** 
* 
* Given an array of non-negative integers, you are initially positioned at the first index of the array.
* 
* Each element in the array represents your maximum jump length at that position. 
* 
* Your goal is to reach the last index in the minimum number of jumps.
* 
* For example:
* Given array A = [2,3,1,1,4]
* 
* The minimum number of jumps to reach the last index is 2. 
* (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
* 
*               
**********************************************************************************/


//greedy algorithm
//16ms
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
		int res = 1;
		int l = 0, r = nums[0];
		int maxL = r;
		while(maxL < nums.size() - 1){
			int newL = -1;
			for(int i = l; i <=r; i++){
				if (i + nums[i] > maxL){
					maxL = i + nums[i];
					newL = i;
					if (maxL >= (nums.size()-1)){return res + 1;}  //will reach in next step
				}
			}
			l = newL;
			r = maxL;
			res++; //ready for next step
		}
		return res;
    }
};}
};
