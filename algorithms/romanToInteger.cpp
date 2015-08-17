// Source : https://leetcode.com/problems/roman-to-integer/
// Author : Siyuan Xu
// Date   : 2015-08-02

/********************************************************************************** 
* 
* Given a roman numeral, convert it to an integer.
* 
* Input is guaranteed to be within the range from 1 to 3999.
*               
**********************************************************************************/

//literate characters, add each value unless this character is lower than the next character. Minus the value in this case!
//36ms
class Solution1 {
private:
    int romanDigitToInt(char c){
        switch(c){
            case 'I':   return 1;
            case 'V':   return 5;
            case 'X':   return 10;
            case 'L':   return 50;
            case 'C':   return 100;
            case 'D':   return 500;
            case 'M':   return 1000;
            default:    return 0;
        }
    }
public:
    int romanToInt(string s) {
        int res = 0;
        int num = 0;
        for(int i = 0; i<s.size(); i++){
            num = romanDigitToInt(s[i]);
            if ((i<s.size() - 1) && (num < romanDigitToInt(s[i+1]))){
                res -= num;
            }
            else {
                res += num;
            }
        }
        return res;
        
    }
};
