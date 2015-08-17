// Source : https://leetcode.com/problems/string-to-integer-atoi/
// Author : Siyuan Xu
// Date   : 2015-08-1

/********************************************************************************** 
* 
* Implement atoi to convert a string to an integer.
* 
* Hint: Carefully consider all possible input cases. If you want a challenge, 
*       please do not see below and ask yourself what are the possible input cases.
* 
* Notes: 
*   It is intended for this problem to be specified vaguely (ie, no given input specs). 
*   You are responsible to gather all the input requirements up front. 
* 
* 
* Requirements for atoi:
* 
* The function first discards as many whitespace characters as necessary until the first 
* non-whitespace character is found. Then, starting from this character, takes an optional 
* initial plus or minus sign followed by as many numerical digits as possible, and interprets 
* them as a numerical value.
* 
* The string can contain additional characters after those that form the integral number, 
* which are ignored and have no effect on the behavior of this function.
* 
* If the first sequence of non-whitespace characters in str is not a valid integral number, 
* or if no such sequence exists because either str is empty or it contains only whitespace 
* characters, no conversion is performed.
* 
* If no valid conversion could be performed, a zero value is returned. If the correct value 
* is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) 
* is returned.
*               
**********************************************************************************/

//12ms
class Solution {
public:
    int myAtoi(string str) {
        int k = 0;
		int sign = 1;
		long res = 0;
		while (k<str.size() && str[k] ==' ') {
			k++;
		}
		if (str[k] == '-') sign = -1, k++;
		else if (str[k] == '+') k++;
		while (k < str.size() && str[k]>='0' && str[k] <= '9') {
			res = res * 10 + sign * (str[k] - '0');
			if (res > INT_MAX) return INT_MAX;
			if (res < INT_MIN) return INT_MIN;
			k++;
		}
		return res;
        
    }
};
