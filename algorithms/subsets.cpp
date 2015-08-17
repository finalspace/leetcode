// Source : https://leetcode.com/problems/subsets/
// Author : Siyuan Xu
// Date   : 2014-08-12

/********************************************************************************** 
* 
* Given a set of distinct integers, S, return all possible subsets.
* 
* Note:
* 
* Elements in a subset must be in non-descending order.
* The solution set must not contain duplicate subsets.
* 
* For example,
* If S = [1,2,3], a solution is:
* 
* [
*   [3],
*   [1],
*   [2],
*   [1,2,3],
*   [1,3],
*   [2,3],
*   [1,2],
*   []
* ]
* 
*               
**********************************************************************************/

//4ms(best)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //iterative
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		res.push_back(vector<int>(0, 0));
		for (int i = 0; i < n; i++) {
			int resSize = res.size();
			for (int j = 0; j < resSize; j++) {
				res.push_back(res[j]);
				res.back().push_back(nums[i]);
			}
		}
		return res;
    }
};

//8ms(good)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
		vector<int> sln;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int total = pow(2, n);
		for (int i = 0; i < total; i++) {
			sln.clear();
			for (int j = 0; j < n; j++) {
				if (i >> j & 1)
					sln.push_back(nums[j]);
			}
			res.push_back(sln);
		}
		return res;
    }
};
