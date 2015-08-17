// Source : https://leetcode.com/problems/minimum-path-sum/
// Author : Siyuan Xu
// Date   : 2015-08-10

/********************************************************************************** 
* 
* Given a m x n grid filled with non-negative numbers, find a path from top left to 
* bottom right which minimizes the sum of all numbers along its path.
* 
* Note: You can only move either down or right at any point in time.
*               
**********************************************************************************/

//1d rolling dp
//28ms
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
		int m = grid.size();
		int n = grid[0].size();
		vector<int> dp(n + 1, INT_MAX);
		dp[n - 1] = 0;
		for (int i = m - 1; i >= 0; i--) {
			for(int j = n - 1; j >= 0; j--) {
				dp[j] = min(dp[j], dp[j + 1]) + grid[i][j];
			}
		}
		return dp[0];
    }
};
