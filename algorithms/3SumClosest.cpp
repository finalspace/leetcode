// Source : https://leetcode.com/problems/3sum-closest/
// Author : Siyuan
// Date   : 2015-08-03

/********************************************************************************** 
* 
* Given an array S of n integers, find three integers in S such that the sum is 
* closest to a given number, target. Return the sum of the three integers. 
* You may assume that each input would have exactly one solution.
* 
*     For example, given array S = {-1 2 1 -4}, and target = 1.
* 
*     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
* 
*               
**********************************************************************************/

//12ms
class Solution1 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
		int ans = nums[0] + nums[1] + nums[2];
		for(int i = 0; i< nums.size() - 2; i++){
			int j = i + 1;
			int k = nums.size() - 1;
			while(j<k){
			    int sum = nums[i] + nums[j] + nums[k];
				ans = (abs(target - sum)<abs(target - ans)) ? sum : ans;
				(sum > target) ? k-- : j++;
				if (sum == target)
					return target;
			}
		}
		return ans;
        
    }
};


//20ms
class Solution2 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
		    int minDiff = target - (nums[0] + nums[1] + nums[2]);
		    int goal = 0;
	    	for(int i = 0; i< nums.size() - 2; i++){
			  goal = target - nums[i];
		  	int j = i + 1;
		  	int k = nums.size() - 1;
		  	while(j<k){
				minDiff = (abs(nums[j] + nums[k] - goal)<abs(minDiff)) ? target - nums[i] - nums[j] - nums[k] : minDiff;
				if (nums[j] + nums[k] < goal){
					j++;
				} else if (nums[j] + nums[k] > goal){
					k--;
				} else{
					return target;
				}
			}
		}
		return target - minDiff;
        
    }
};
