// Source : https://leetcode.com/problems/permutations/
// Author : Siyuan Xu
// Date   : 2015-08-11

/********************************************************************************** 
* 
* Given a collection of numbers, return all possible permutations.
* 
* For example,
* [1,2,3] have the following permutations:
* [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
* 
*               
**********************************************************************************/

//cheat
//12ms(best)
class Solution1 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
		if (nums.empty()) return res;
		sort(nums.begin(), nums.end());
		int n = 1;
		for(int i = 2; i <= nums.size(); i++){
			n*=i;
		}
		while(n>0){
			res.push_back(nums);
			next_permutation(nums.begin(), nums.end());
			n--;
		}
		return res;
    }
};

//dfs
//12ms(best)
class Solution2 {
public:
    void permute_recursive(vector<int> nums, int k, vector<vector<int>>& res){
		if (k==nums.size()-1){
			res.push_back(nums);
			return;
		}
		for(int i = k; i < nums.size(); i++){
			swap(nums[k], nums[i]);
			permute_recursive(nums, k + 1, res);
		}
	}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		permute_recursive(nums, 0, res);
		return res;
    }
};

//dfs 
//not idea, since order is not correct
//16ms
class Solution3 {
public:
    void permute_recursive(vector<int>& nums, int k, vector<vector<int>>& res){
		if (k==nums.size()-1){
			res.push_back(nums);
			return;
		}
		for(int i = k; i < nums.size(); i++){
			swap(nums[k], nums[i]);
			permute_recursive(nums, k + 1, res);
			swap(nums[k], nums[i]);
		}
	}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		permute_recursive(nums, 0, res);
		return res;
    }
};
