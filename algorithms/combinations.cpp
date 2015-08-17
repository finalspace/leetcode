// Source : https://leetcode.com/problems/combinations/
// Author : Siyuan Xu
// Date   : 2015-08-12

/********************************************************************************** 
* 
* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
* 
* For example,
* If n = 4 and k = 2, a solution is:
* 
* [
*   [2,4],
*   [3,4],
*   [2,3],
*   [1,2],
*   [1,3],
*   [1,4],
* ]
* 
*               
**********************************************************************************/

//12ms(good)
class Solution {
public:
  void dfs(vector<vector<int>> &res, vector<int>& sln, int n, int k, int p, int d){
		if (p == k){
			res.push_back(sln);
			return;
		}
		for(int i = d; i <= n - k + p + 1; i++){
			sln[p] = i;
			dfs(res, sln, n, k, p + 1, i + 1);
		}
	}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
		vector<int> sln(k, 0);
		dfs(res, sln, n, k, 0, 1);
		return res;
    }
};
