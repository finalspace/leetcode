// Source : https://leetcode.com/problems/valid-number/
// Author : Siyuan Xu
// Date   : 2015-08-10

/********************************************************************************** 
* 
* Validate if a given string is numeric.
* 
* Some examples:
* "0" => true
* "   0.1  " => true
* "abc" => false
* "1 a" => false
* "2e10" => true
* 
* Note: It is intended for the problem statement to be ambiguous. 
*       You should gather all requirements up front before implementing one.
* 
*               
**********************************************************************************/


//Deterministic Finite Automation(DFA)
//12ms(good)
class Solution {
public:
    bool isNumber(string s) {
        while (!s.empty() && s[0] == ' ') s.erase(s.begin());
		while (!s.empty() && s[s.size() - 1] == ' ') s.erase(s.end() - 1);
		if (s.empty()) return false;
		int state = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '+' || s[i] == '-') {
				if (state == 0) state = 1;
				else if (state == 3) state = 4;
				else return false;
			}
			else if (s[i] == '.') {
				if (state == 0) state = 6;
				else if (state == 1) state = 6;
				else if (state == 2) state = 7;
				else return false;
			}
			else if (s[i] >= '0' && s[i] <= '9') {
				if (state == 0) state = 2;
				else if (state == 1) state = 2;
				else if (state == 2) state = 2;
				else if (state == 6) state = 7;
				else if (state == 7) state = 7;
				else if (state == 3) state = 5;
				else if (state == 4) state = 5;
				else if (state == 5) state = 5;
				else return false;
			}
			else if (s[i] == 'e' || s[i] == 'E') {
				if (state == 2) state = 3;
				else if (state == 7) state = 3;
				else return false;
			}
			else return false;
		}
		return (state == 2 || state == 5 || state == 7);
    }
};
