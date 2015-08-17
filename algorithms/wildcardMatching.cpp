// Source : https://leetcode.com/problems/wildcard-matching/
// Author : Siyuan Xu
// Date   : 2015-08-10

/********************************************************************************** 
* 
* Implement wildcard pattern matching with support for '?' and '*'.
* 
* '?' Matches any single character.
* '*' Matches any sequence of characters (including the empty sequence).
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
* isMatch("aa", "*") → true
* isMatch("aa", "a*") → true
* isMatch("ab", "?*") → true
* isMatch("aab", "c*a*b") → false
* 
*               
**********************************************************************************/

//why it is ok to update the star pos
//suppose we have
//...|...c......c.....
//...|*c*.....
//suppose it matches before the seperator
//
// 1) if we don't update the star position, also means if we don't match the first 'c', also means we don't think this is the solution
//    then we are looking for next 'c'
//    ...|...c......c|.......
//    ...|*c|*.....
// 2) but if we update the star position, means we match the first 'c'
//    ...|...c|......c.....
//    ...|*c|*.....
//
//then we are searching solutions after the second seperators of the two strings
//which covers the first case, because the second star can cover the second 'c', see below
//and we will eventually come to this situation (the third seperator of the first string is the matchPos we iterate)
//think in this way, we can treate '*' as "**"
//    ...|...c|......c|.....
//    ...|*c|*|*.....
//
//generally, if we don't update the first star position and have a solution,
//update the star will reach the same

//16ms(best)
class Solution1 {
public:
	bool isMatch(string s, string p) {
	    int i = 0;
		int j = 0;
		int starPos = -1;
		int matchPos = -1;
		p += '#';
		while (i < s.size()) {
			if ((s[i] == p[j]) || (p[j] == '?')) { i++; j++; continue; }
			if (p[j] == '*') { starPos = j++; matchPos = i; continue; }
			if (starPos >= 0) { j = starPos + 1; i = ++matchPos; continue; }
			return false;
		}
		while (j < p.size() && p[j] == '*')
			j++;
		return j == p.size() - 1;
	}
};


//16ms(best)
class Solution2 {
public:
	bool isMatch(string s, string p) {
	    int m = s.length(), n = p.length();
        int i = 0, j = 0, asterick = -1, match;
        while (i < m) {
            if (j < n && p[j] == '*') {
                match = i;  
                asterick = j++;
            }
            else if (j < n && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            }
            else if (asterick >= 0) {
                i = ++match;
                j = asterick + 1;
            }
            else return false;
        }
        while (j < n && p[j] == '*') j++;
        return j == n;
	}
};
