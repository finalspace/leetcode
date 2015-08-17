// Source : https://leetcode.com/problems/regular-expression-matching/
// Author : Hao Chen
// Date   : 2014-08-24

/********************************************************************************** 
* 
* Implement regular expression matching with support for '.' and '*'.
* 
* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.
* 
* The matching should cover the entire input string (not partial).
* 
* The function prototype should be:
* bool isMatch(const char *s, const char *p)
* 
* Some examples:
* isMatch("aa","a") → false
* isMatch("aa","aa") → true
* isMatch("aaa","aa") → false
* isMatch("aa", "a*") → true
* isMatch("aa", ".*") → true
* isMatch("ab", ".*") → true
* isMatch("aab", "c*a*b") → true
* 
*               
**********************************************************************************/

//dp 20ms
class Solution1 {
private:
	bool isTokenMatch(string s, string token) {
		char ch = token[0];
		if (token.size()==1) {
			return (s.size() == 1) && ((ch == '.')||(s== token));
		}
		else {
			bool flag = false;
			if (ch == '.') return true;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] != ch)
					return false;
			}
			return true;
		}
	}
	vector<string> getTokens(string p) {
		vector<string> tokens;
		int k = 0;
		while (k < p.size()) {
			string token;
			token.push_back(p[k++]);
			if ((k<p.size()) && (p[k] == '*')) {
				token.push_back(p[k++]);
			}
			tokens.push_back(token);
		}
		return tokens;
	}
public:
	bool isMatch(string s, string p) {
		vector<string> tokens;
		tokens = getTokens(p);
		vector<vector<bool>> dp;
		for (int i = 0; i < s.size() + 1; i++) {
			vector<bool> v1(tokens.size() + 1, false);
			dp.push_back(v1);
		}

		dp[s.size()][tokens.size()] = true;
		for (int j = tokens.size() - 1; j >= 0; j--) {
			dp[s.size()][j] = dp[s.size()][j + 1] && (tokens[j].size() == 2);
		}

		for (int i = s.size() - 1; i >= 0; i--) {
			for (int j = tokens.size() - 1; j >= 0; j--) {
				if (tokens[j].size() == 1) {
					dp[i][j] = isTokenMatch(s.substr(i, 1), tokens[j]) && (dp[i+1][j+1]);
				}
				else {
					dp[i][j] = dp[i][j+1] || 
						(isTokenMatch(s.substr(i, 1), tokens[j]) && ((dp[i+1][j+1])||(dp[i+1][j])));
				}
			}
		}
		return dp[0][0];
	}
};

//DP 24ms
class Solution2 {
private:
	bool isTokenMatch(string s, string token) {
		char ch = token[0];
		if (token.size()==1) {
			return (s.size() == 1) && ((ch == '.')||(s== token));
		}
		else {
			bool flag = false;
			if (ch == '.') return true;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] != ch)
					return false;
			}
			return true;
		}
	}
	vector<string> getTokens(string p) {
		vector<string> tokens;
		int k = 0;
		while (k < p.size()) {
			string token;
			token.push_back(p[k++]);
			if ((k<p.size()) && (p[k] == '*')) {
				token.push_back(p[k++]);
			}
			tokens.push_back(token);
		}
		return tokens;
	}
public:
	bool isMatch(string s, string p) {
		vector<string> tokens;
		tokens = getTokens(p);
		vector<vector<bool>> dp;
		for (int i = 0; i < s.size() + 1; i++) {
			vector<bool> v1(tokens.size() + 1, false);
			dp.push_back(v1);
		}

		dp[s.size()][tokens.size()] = true;
		for (int j = tokens.size() - 1; j >= 0; j--) {
			dp[s.size()][j] = dp[s.size()][j + 1] && (tokens[j].size() == 2);
		}

		for (int i = s.size() - 1; i >= 0; i--) {
			for (int j = tokens.size() - 1; j >= 0; j--) {
				if (tokens[j].size() == 1) {
					dp[i][j] = isTokenMatch(s.substr(i, 1), tokens[j]) && (dp[i+1][j+1]);
				}
				else {
					dp[i][j] = dp[i][j+1] || 
						(isTokenMatch(s.substr(i, 1), tokens[j]) && ((dp[i+1][j+1])||(dp[i+1][j])));
				}
			}
		}
		return dp[0][0];
	}
};
