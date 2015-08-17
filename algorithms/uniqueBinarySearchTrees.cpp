// Source : https://oj.leetcode.com/problems/unique-binary-search-trees/
// Author : Hao Chen
// Date   : 2014-06-25

/********************************************************************************** 
* 
* Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
* 
* For example,
* Given n = 3, there are a total of 5 unique BST's.
* 
*    1         3     3      2      1
*     \       /     /      / \      \
*      3     2     1      1   3      2
* 
*               
**********************************************************************************/

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
		dp[0] = 1; dp[1] = 1;
		for(int i = 2; i <= n; i++){
			for(int j = 1; j <= i; j++){
				dp[i] += dp[j - 1] *  dp[i - j];
			}
		}
		return dp[n];
    }
};
