// Source : https://leetcode.com/problems/permutations-ii/
// Author : Siyuan Xu
// Date   : 2014-08-11

/********************************************************************************** 
* 
* Given a collection of numbers that might contain duplicates, return all possible unique permutations.
* 
* For example,
* [1,1,2] have the following unique permutations:
* [1,1,2], [1,2,1], and [2,1,1].
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
