// Source : https://leetcode.com/problems/scramble-string/
// Author : Siyuan Xu
// Date   : 2015-08-14

/********************************************************************************** 
* 
* Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
* 
* Below is one possible representation of s1 = "great":
* 
*     great
*    /    \
*   gr    eat
*  / \    /  \
* g   r  e   at
*            / \
*           a   t
* 
* To scramble the string, we may choose any non-leaf node and swap its two children.
* 
* For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
* 
*     rgeat
*    /    \
*   rg    eat
*  / \    /  \
* r   g  e   at
*            / \
*           a   t
* 
* We say that "rgeat" is a scrambled string of "great".
* 
* Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
* 
*     rgtae
*    /    \
*   rg    tae
*  / \    /  \
* r   g  ta  e
*        / \
*       t   a
* 
* We say that "rgtae" is a scrambled string of "great".
* 
* Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
* 
*               
**********************************************************************************/

//dfs + pruning
//4ms(best)
class Solution1 {
public:
	bool helper(string &s1, string &s2, int p1, int p2, int l) {
		if (l == 1)
			return s1[p1] == s2[p2];
		bool flag = false;
		int count[26];
		fill_n(count, 26, 0);
		for (int i = 0; i < l; i++) {
			count[s1[p1 + i] - 'a']++;
			count[s2[p2 + i] - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (count[i] != 0)
				return false;
		}

		for (int k = 1; k <= l - 1 && !flag; k++) {
			flag = (helper(s1, s2, p1, p2, k) && helper(s1, s2, p1 + k, p2 + k, l - k))
				|| (helper(s1, s2, p1, p2 + l - k, k) && helper(s1, s2, p1 + k, p2, l - k));
		}
		return flag;
	}
	bool isScramble(string s1, string s2) {
		if (s1.size() != s2.size()) return false;
		return helper(s1, s2, 0, 0, s1.size());
	}
};


//dfs + pruning + caching
//8ms(slower than dfs + pruning)
class Solution2 {
public:
	bool helper(string &s1, string &s2, int*** cache, int p1, int p2, int l) {
		if (l == 1)
			return s1[p1] == s2[p2];
		if (cache[p1][p2][l] != -1)
			return cache[p1][p2][l];
		bool flag = false;
		int count[26];
		fill_n(count, 26, 0);
		for (int i = 0; i < l; i++) {
			count[s1[p1 + i] - 'a']++;
			count[s2[p2 + i] - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (count[i] != 0)
				return false;
		}

		for (int k = 1; k <= l - 1 && !flag; k++) {
			flag = (helper(s1, s2, cache, p1, p2, k) && helper(s1, s2, cache, p1 + k, p2 + k, l - k))
				|| (helper(s1, s2, cache, p1, p2 + l - k, k) && helper(s1, s2, cache, p1 + k, p2, l - k));
		}
		if (cache[p1][p2][l] == -1)
			cache[p1][p2][l] = flag ? 1 : 0;
		return flag;
	}
	bool isScramble(string s1, string s2) {
		if (s1.size() != s2.size()) return false;
		int n = s1.size();
		int*** cache = new int**[n];
		for (int i = 0; i < n; i++) {
			cache[i] = new int*[n];
			for (int j = 0; j < n; j++) {
				cache[i][j] = new int[n + 1];
				fill_n(cache[i][j], n + 1, -1);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cache[i][j][1] = (s1[i] == s2[j]) ? 1 : 0;
			}
		}
		return helper(s1, s2, cache, 0, 0, s1.size());
	}
};


//3d dp
//24ms(slower)
class Solution3 {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
		int n = s1.size();
		bool*** dp = new bool**[n];
		for (int i = 0; i < n; i++) {
			dp[i] = new bool*[n];
			for (int j = 0; j < n; j++) {
				dp[i][j] = new bool[n + 1];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j][1] = s1[i] == s2[j];
			}
		}
		for (int l = 2; l <= n; l++) {
			for (int i = 0; i <= n - l; i++) {
				for (int j = 0; j <= n - l; j++) {
					for (int k = 1; k <= l - 1 && !dp[i][j][l]; k++) {
						dp[i][j][l] = (dp[i][j][k] && dp[i + k][j + k][l - k])
							|| (dp[i][j + l - k][k] && dp[i + k][j][l - k]);
					}
				}
			}
		}
		return dp[0][0][n];
    }
};
