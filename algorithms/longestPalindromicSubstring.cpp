// Source : https://leetcode.com/problems/longest-palindromic-substring/
// Author : Siyuan Xu
// Date   : 2015-08-17

/********************************************************************************** 
* 
* Given a string S, find the longest palindromic substring in S. 
* You may assume that the maximum length of S is 1000, 
* and there exists one unique longest palindromic substring.
*               
**********************************************************************************/

//128ms
class Solution1 {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
		int start = 0;
		int longest = 1;
		for (int i = 1; i < s.size(); i++) {
			int j = i - 1;
			int k = i + 1;
			while ((j >= 0) && (s[j] == s[i])) {
				j--;
			}
			while ((k<s.size()) && (s[k] == s[i])) {
				k++;
			}
			while ((j >= 0) && (k < s.size()) && (s[j] == s[k])) {
				j--;
				k++;
			}
			if (k - j - 1 > longest) {
				start = j + 1;
				longest = k - j - 1;
			}
		}
		return s.substr(start, longest);
    }
};

//72ms
class Solution2 {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
		int start = 0;
		int longest = 1;
		for (int i = 1; i < s.size(); i++) {
			if ((s.size() - i) * 2 - 1 < longest)
				break;
			int j = i - 1;
			int k = i + 1;
			while ((j >= 0) && (s[j] == s[i])) {
				j--;
			}
			while ((k<s.size()) && (s[k] == s[i])) {
				k++;
			}
			while ((j >= 0) && (k < s.size()) && (s[j] == s[k])) {
				j--;
				k++;
			}
			if (k - j - 1 > longest) {
				start = j + 1;
				longest = k - j - 1;
			}
		}
		return s.substr(start, longest);
    }
};

//8ms
class Solution3 {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
    if (s.size() == 1) return s;
    int min_start = 0, max_len = 1;
    for (int i = 0; i < s.size();) {
      if (s.size() - i <= max_len / 2) break;
      int j = i, k = i;
      while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
      i = k+1;
      while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
      int new_len = k - j + 1;
      if (new_len > max_len) { min_start = j; max_len = new_len; }
    }
    return s.substr(min_start, max_len);
    }
};

//8ms
class Solution4 {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
		int start = 0;
		int longest = 1;
		for (int i = 1; i < s.size(); i++) {
			if ((s.size() - i) * 2 - 1 < longest)
				break;
			int j = i - 1;
			int k = i + 1;
			while ((j >= 0) && (s[j] == s[i])) {
				j--;
			}
			while ((k<s.size()) && (s[k] == s[i])) {
				k++;
			}
			i = k - 1;
			while ((j >= 0) && (k < s.size()) && (s[j] == s[k])) {
				j--;
				k++;
			}
			if (k - j - 1 > longest) {
				start = j + 1;
				longest = k - j - 1;
			}
		}
		return s.substr(start, longest);
    }
};
