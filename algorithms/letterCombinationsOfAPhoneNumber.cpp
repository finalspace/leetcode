// Source : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author : Siyuan Xu
// Date   : 2014-08-03

/********************************************************************************** 
* 
* Given a digit string, return all possible letter combinations that the number could represent.
* 
* A mapping of digit to letters (just like on the telephone buttons) is given below.
* 
* Input:Digit string "23"
* Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
* 
* Note:
* Although the above answer is in lexicographical order, your answer could be in any order you want.
* 
*               
**********************************************************************************/

//dfs 0ms
class Solution {
public:
    void dfs(string table[], string digits, string res, vector<string> &ans) {
		if (digits.empty()) {
			if (!res.empty()) ans.push_back(res);
			return;
		}
		int digit = digits[0] - '0';
		for (int i = 0; i < table[digit].size(); i++) {
			dfs(table, digits.substr(1,digits.size()-1), res+table[digit][i], ans);
		}
	}
    vector<string> letterCombinations(string digits) {
        string table[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		vector<string> ans;
		string res = "";
		dfs(table, digits, res, ans);
		return ans;
        
    }
};
