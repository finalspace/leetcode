// Source : https://leetcode.com/problems/combination-sum/
// Author : Siyuan Xu
// Date   : 2015-08-09

/********************************************************************************** 
* 
* Given a set of candidate numbers (C) and a target number (T), find all unique combinations 
* in C where the candidate numbers sums to T. 
* 
* The same repeated number may be chosen from C unlimited number of times.
* 
* Note:
* 
* All numbers (including target) will be positive integers.
* Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
* The solution set must not contain duplicate combinations.
* 
* For example, given candidate set 2,3,6,7 and target 7, 
* A solution set is: 
* [7] 
* [2, 2, 3] 
* 
*               
**********************************************************************************/

//dfs
//16ms(best)
class Solution {
public:
void dfs(vector<vector<int>>& res, vector<int>& ans, vector<int>& candidates, int target, int k, int sum) {
		if (sum == target) {
			res.push_back(ans);
			return;
		}
		for (int i = k; i < candidates.size(); i++) {
			if (sum + candidates[i] <= target) {
				ans.push_back(candidates[i]);
				dfs(res, ans, candidates, target, i, sum + candidates[i]);
				ans.pop_back();
			}
		}
	}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
		vector<int> ans;
		sort(candidates.begin(), candidates.end());
		dfs(res, ans, candidates, target, 0, 0);
		return res;
    }
};

//52ms
class Solution2 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
    vector< vector< vector<int> > > combinations(target + 1, vector<vector<int>>());
    combinations[0].push_back(vector<int>());
    for (auto& score : candidates)
        for (int j = score; j <= target; j++){
            auto sls = combinations[j - score];
            if (sls.size() > 0) {
                for (auto& s : sls)
                    s.push_back(score);
                combinations[j].insert(combinations[j].end(), sls.begin(), sls.end());
            }
        }
    return combinations[target];
    }
};
