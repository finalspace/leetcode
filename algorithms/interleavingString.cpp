// Source : https://leetcode.com/problems/interleaving-string/
// Author : Siyuan Xu
// Date   : 2015-08-15

/********************************************************************************** 
* 
* Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
* 
* For example,
* Given:
* s1 = "aabcc",
* s2 = "dbbca",
* 
* When s3 = "aadbbcbcac", return true.
* When s3 = "aadbbbaccc", return false.
* 
*               
**********************************************************************************/

//8ms(medium)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
		if (l1 + l2 != l3) return false;
        vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1, false));
		dp[0][0] = true;
		for(int i = 1; i <= l1; i++){
			dp[i][0] = s1.substr(0, i) == s3.substr(0, i);
			if (!dp[i][0]) break;
		}
		for(int j = 1; j <= l2; j++){
			dp[0][j] = s2.substr(0, j) == s3.substr(0, j);
			if (!dp[0][j]) break;
		}
		for(int i = 1; i <= l1; i++){
			for(int j = 1; j <= l2; j++){
				dp[i][j] = (s1[i - 1] == s3[i+j-1] && dp[i-1][j]) || (s2[j-1] == s3[i+j-1] && dp[i][j-1]);
			}
		}
		return dp[l1][l2];
    }
};
