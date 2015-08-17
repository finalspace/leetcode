// Source : https://leetcode.com/problems/length-of-last-word/
// Author : Siyuan Xu
// Date   : 2015-08-12

/********************************************************************************** 
* 
* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
* return the length of last word in the string.
* 
* If the last word does not exist, return 0.
* 
* Note: A word is defined as a character sequence consists of non-space characters only.
* 
* For example, 
* Given s = "Hello World",
* return 5.
* 
*               
**********************************************************************************/


//4ms(best)
class Solution {
public:
    int lengthOfLastWord(string s) {
		auto last = s.find_last_not_of(' ');
		if (last != string::npos) { s.erase(last + 1, s.size() - last - 1); }
		else return 0;
		last = s.find_last_of(' ');
		return (last==string::npos) ? s.size() : s.size() - last - 1;
    }
};


//4ms(best)
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.find(' ') == string::npos) { return s.size(); }
		auto last = s.find_last_not_of(' ');
		if (last != string::npos) { s.erase(last + 1, s.size() - last - 1); }
		else return 0;
		last = s.find_last_of(' ');
		return (last==string::npos) ? s.size() : s.size() - last - 1;
    }
};
