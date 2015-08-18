// Source : https://leetcode.com/problems/combination-sum-ii/
// Author : Siyuan Xu
// Date   : 2015-08-09

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
//12ms
class Solution1 {
public:
void dfs(vector<vector<int>>& res, vector<int>& ans, vector<int>& candidates, int target, int k, int sum) {
		if (sum == target) {
			res.push_back(ans);
			return;
		}
		for (int i = k; i < candidates.size(); i++) {
			if (i == k || candidates[i - 1] != candidates[i]) {
				if (sum + candidates[i] <= target) {
					ans.push_back(candidates[i]);
					dfs(res, ans, candidates, target, i + 1, sum + candidates[i]);
					ans.pop_back();
				}
			}
		}
	}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
		vector<int> ans;
		sort(candidates.begin(), candidates.end());
		dfs(res, ans, candidates, target, 0, 0);
		return res;
    }
};

//dfs
//12ms
class Solution2 {
public:
void dfs(vector<vector<int>>& res, vector<int>& ans, vector<int>& candidates, int target, int k, int sum) {
		if (sum == target) {
			res.push_back(ans);
			return;
		}
		for (int i = k; i < candidates.size(); i++) {
			if (sum + candidates[i] <= target) {
				ans.push_back(candidates[i]);
				dfs(res, ans, candidates, target, i+1, sum + candidates[i]);
				ans.pop_back();
				while (i + 1 < candidates.size() && candidates[i + 1] == candidates[i])
					i++;
			}
		}
	}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
		vector<int> ans;
		sort(candidates.begin(), candidates.end());
		dfs(res, ans, candidates, target, 0, 0);
		return res;
    }
};
