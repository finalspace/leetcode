// Source : https://leetcode.com/problems/zigzag-conversion/
// Author : Siyuan Xu
// Date   : 2015-07-17

/********************************************************************************** 
* 
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
* (you may want to display this pattern in a fixed font for better legibility)
* 
* P   A   H   N
* A P L S I I G
* Y   I   R
* 
* And then read line by line: "PAHNAPLSIIGYIR"
* 
* Write the code that will take a string and make this conversion given a number of rows:
* 
* string convert(string text, int nRows);
* 
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
* 
*               
**********************************************************************************/

//24ms
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
		string res = "";
		string* rows = new string[numRows];
		int dir = 1;
		int k = 0;
		for (int i = 0; i < s.size(); i++) {
			rows[k].push_back(s[i]);
			if ((k + dir < 0) || (k + dir >= numRows)) {
				dir = -dir;
			}
			k = k + dir;
		}

		for (int i = 0; i < numRows; i++) {
			res += rows[i];
		}
		return res;
        
    }
};
