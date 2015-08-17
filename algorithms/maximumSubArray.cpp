
// Source : https://leetcode.com/problems/maximum-subarray/
// Author : Siyuan Xu
// Date   : 2015-08-12

/********************************************************************************** 
* 
* Find the contiguous subarray within an array (containing at least one number) 
* which has the largest sum.
* 
* For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
* the contiguous subarray [4,−1,2,1] has the largest sum = 6.
* 
* More practice:
* 
* If you have figured out the O(n) solution, try coding another solution using 
* the divide and conquer approach, which is more subtle.
* 
*               
**********************************************************************************/

//8ms(best)
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
		int act = nums[0];
		for(int i = 1; i < nums.size(); i++){
		    if (act<0) act = nums[i];
		    else act +=nums[i];
			res = max(res, act);
		}
		return res;
    }
};

//concise
//12ms(good)
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], act = nums[0];
		for(int i = 1; i < nums.size(); i++){
		    act = (act >= 0) ? act+nums[i] : nums[i];
			res = max(res, act);
		}
		return res;
    }
};

//12ms(good)
class Solution3 {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
		int act = nums[0];
		for(int i = 1; i < nums.size(); i++){
		    if (act<0 && nums[i] > 0) act = nums[i];
		    else if(nums[i] > 0) act +=nums[i];
			else if (act > 0 && nums[i] <=0){
				act += nums[i];
			}
			else act = nums[i];
			if(act > res){
				res = act;
			}
		}
		return res;
    }
};

//12ms(good)
class Solution4 {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
		int act = nums[0];
		for(int i = 1; i < nums.size(); i++){
		    if (act<0) act = nums[i];
		    else act +=nums[i];
			if(act > res){
				res = act;
			}
		}
		return res;
    }
};
