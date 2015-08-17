// Source : https://leetcode.com/problems/generate-parentheses/
// Author : Siyuan Xu
// Date   : 2014-06-29

/********************************************************************************** 
* 
* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
* 
* For example, given n = 3, a solution set is:
* 
* "((()))", "(()())", "(())()", "()(())", "()()()"
* 
*               
**********************************************************************************/

//dp 0ms
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> f;
		f.push_back(vector<string>(1, ""));
		f.push_back(vector<string>(1, "()"));

		for (int i = 2; i <= n; i++) {
			vector<string> temp;
			for (int k = 0; k < f[i - 1].size(); k++) {
				temp.push_back("(" + f[i - 1][k] + ")");
			}
			for (int j = 1; j < i-1; j++) {
				for (int a = 0; a < f[j].size(); a++) {
					for (int b = 0; b < f[i - j -1].size(); b++) {
						temp.push_back("("+f[j][a]+")"+f[i-j-1][b]);
					}
				}
			}
			for (int k = 0; k < f[i - 1].size(); k++) {
				temp.push_back("()" + f[i - 1][k]);
			}
			f.push_back(temp);
		}
		return f[n];
        
    }
};

//dfs 4ms
class Solution2 {
public:
void dfs(vector<string> &res, string ans, int lLeft, int rLeft){
		if (lLeft==0 && rLeft == 0){
			res.push_back(ans);
			return;
		}
		if(lLeft>0){
			dfs(res, ans+"(", lLeft - 1, rLeft);
		}
		if(lLeft < rLeft){
			dfs(res, ans+")", lLeft, rLeft - 1);
		}
	}
    vector<string> generateParenthesis(int n) {
        vector<string> res;
		dfs(res, "", n, n);
		return res;
        
    }
};
