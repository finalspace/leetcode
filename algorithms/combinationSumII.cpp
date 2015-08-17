// Source : https://leetcode.com/problems/combination-sum-ii/
// Author : Siyuan Xu
// Date   : 2015-08-11

/********************************************************************************** 
* 
* Given a collection of candidate numbers (C) and a target number (T), find all 
* unique combinations in C where the candidate numbers sums to T.
* 
* Each number in C may only be used once in the combination.
* 
* Note:
* 
* > All numbers (including target) will be positive integers.
* > Elements in a combination (a1, a2, … , ak) must be in non-descending order. 
*   (ie, a1 ≤ a2 ≤ … ≤ ak).
* > The solution set must not contain duplicate combinations.
* 
* For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
* A solution set is: 
* [1, 7] 
* [1, 2, 5] 
* [2, 6] 
* [1, 1, 6] 
* 
*               
**********************************************************************************/

//dfs
//nice swap
//32ms (good)
class Solution {
public:
    void permute_recursive(vector<int> nums, int k, vector<vector<int>>& res){
		if (k==nums.size()-1){
			res.push_back(nums);
			return;
		}
		
	    permute_recursive(nums, k + 1, res);
		for(int i = k + 1; i < nums.size(); i++){
			if (nums[k] == nums[i]){continue;}
			swap(nums[k], nums[i]);
			permute_recursive(nums, k + 1, res);
		}
	}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		permute_recursive(nums, 0, res);
		return res;
    }
};
