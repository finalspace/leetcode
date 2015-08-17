// Source : https://leetcode.com/problems/n-queens/
// Author : Siyuan Xu
// Date   : 2015-08-12

/********************************************************************************** 
* 
* The n-queens puzzle is the problem of placing n queens on an n×n chessboard 
* such that no two queens attack each other.
* 
* Given an integer n, return all distinct solutions to the n-queens puzzle.
* 
* Each solution contains a distinct board configuration of the n-queens' placement, 
* where 'Q' and '.' both indicate a queen and an empty space respectively.
* 
* For example,
* There exist two distinct solutions to the 4-queens puzzle:
* 
* [
*  [".Q..",  // Solution 1
*   "...Q",
*   "Q...",
*   "..Q."],
* 
*  ["..Q.",  // Solution 2
*   "Q...",
*   "...Q",
*   ".Q.."]
* ]
* 
*               
**********************************************************************************/


//plain dfs
//4ms(best)
class Solution1 {
public:
    void dfs(vector<vector<string>>& res, vector<string>& sln, vector<int>& col, vector<int>& diag0, vector<int>& diag1, int k, int n){
		if (k==n){
			res.push_back(sln);
			return;
		}
		for(int i = 0; i < n; i++){
			if ((col[i] == 0) && (diag0[i + k] == 0) && diag1[n - i + k] == 0){
				sln[k][i] = 'Q';
				col[i] = 1; diag0[i + k] = 1; diag1[n - i + k] = 1;
				dfs(res, sln, col, diag0, diag1, k + 1, n);
				col[i] = 0; diag0[i + k] = 0; diag1[n - i + k] = 0;
				sln[k][i] = '.';
			}
		}
	}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
		string row(n, '.');
		vector<string> sln(n, row);
		vector<int> col(n, 0);
		vector<int> diag0(2*n-1, 0);
		vector<int> diag1(2*n-1, 0);
		dfs(res, sln, col, diag0, diag1, 0, n);
		return res;
    }
};
