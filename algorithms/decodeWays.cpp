// Source : https://leetcode.com/problems/decode-ways/
// Author : Siyuan XU
// Date   : 2015-08-14

/********************************************************************************** 
* 
* A message containing letters from A-Z is being encoded to numbers using the following mapping:
* 
* 'A' -> 1
* 'B' -> 2
* ...
* 'Z' -> 26
* 
* Given an encoded message containing digits, determine the total number of ways to decode it.
* 
* For example,
* Given encoded message "12",
* it could be decoded as "AB" (1 2) or "L" (12).
* 
* The number of ways decoding "12" is 2.
* 
*               
**********************************************************************************/

//more space saving dp
//4ms(best)
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
		int dp0, dp1 = 1, dp2 = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == '0') { dp0 = 0; }
			else {
				dp0 = dp1;
				if (i < s.size() - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7'))) {
					dp0 += dp2;
				}
			}
			dp2 = dp1; dp1 = dp0;
		}
		return dp0;
    }
};


//plain rolling 1d dp
//4ms(best)
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
		vector<int> dp(s.size() + 1, 0);
		dp[s.size()] = 1;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == '0') { dp[i] = 0; continue; }
			dp[i] = dp[i + 1];
			if (i < s.size() - 1 && (s[i] == '1' || (s[i]=='2' && s[i + 1] < '7'))) {
				dp[i] += dp[i + 2];
			}
		}
		return dp[0];
    }
};
