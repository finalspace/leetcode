// Source : https://leetcode.com/problems/longest-valid-parentheses/
// Author : Siyuan Xu
// Date   : 2015-08-05

/********************************************************************************** 
* 
* Given a string containing just the characters '(' and ')', 
* find the length of the longest valid (well-formed) parentheses substring.
* 
* For "(()", the longest valid parentheses substring is "()", which has length = 2.
* 
* Another example is ")()())", where the longest valid parentheses substring is "()()", 
* which has length = 4.
* 
*               
**********************************************************************************/

//utilizing stack storing the invalid position
//slighter slower but smart solution
//12ms
class Solution1 {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
		int res = 0;
		for (int i = 0; i < s.size();i ++) {
			if ((s[i] == '(') || (stk.empty())) {
				stk.push(i);
			}
			else if ((!stk.empty()) && (s[stk.top()] == '(')) {
				stk.pop();
			}
			else stk.push(i);
		}
		if (stk.empty()) return s.size();
		res = 0;
		int k = s.size();
		while (!stk.empty()) {
			res = max(res, int(k - stk.top() - 1));
			k = stk.top();
			stk.pop();
		}
		return max(res,k);
    }
};

//dp
//if "(" is before current ")" dp[i] = dp[i-2]
//if ")" is before current ")", and more before is a "(" => "( (...) )" dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
//8ms(best)
class Solution2 {
public:
    int longestValidParentheses(string s) {
        int res = 0;
		vector<int> dp(s.size(), 0);
		for (int i = 1; i < s.size(); i++) {
			if ((s[i]) == '(') {
				dp[i] = 0;
				continue;
			}
			else if (s[i - 1] == '(') {
				if (i-2>=0) dp[i] = dp[i - 2] + 2;
				else dp[i] = 2;
			}
			else if (s[i - 1] == ')') {
				if ((i - dp[i - 1] - 1 >= 0) && (s[i - dp[i - 1] - 1] == '(')) {
					if (i - dp[i - 1] - 2 >= 0) dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
					else dp[i] = dp[i - 1] + 2;
				}
			}
		}
		for (int i = 0; i < s.size(); i++) {
			res = max(res, dp[i]);
		}
		return res;
    }
};

//dp
//if "(" is before current ")" dp[i] = dp[i-2]
//if ")" is before current ")", and more before is a "(" => "( (...) )" dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
//map is slow
//72ms
class Solution3 {
public:
    int longestValidParentheses(string s) {
        int res = 0;
		unordered_map<int, int> dp;
		dp.insert(pair<int, int>(-1, 0));
		dp[0] = 0;
		for (int i = 1; i < s.size(); i++) {
			if ((s[i]) == '(') {
				dp[i] = 0; 
				continue;
			}
			else if (s[i - 1] == '(') {
				dp[i] = dp[i - 2] + 2;
			}
			else if (s[i - 1] == ')') {
				if ((i - dp[i - 1] - 1 >= 0)&&(s[i - dp[i - 1] - 1] == '(')) {
					dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
				}
			}
		}
		for (int i = 0; i < s.size(); i++) {
			res = max(res, dp[i]);
		}
		return res;
    }
};
