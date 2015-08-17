// Source : https://leetcode.com/problems/reverse-integer/
// Author : Siyuan Xu
// Date   : 2014-08-1

/********************************************************************************** 
* 
* Reverse digits of an integer.
* 
* Example1: x =  123, return  321
* Example2: x = -123, return -321
* 
* 
* Have you thought about this?
* 
* Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
* 
* > If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
* 
* > Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, 
*   then the reverse of 1000000003 overflows. How should you handle such cases?
* 
* > Throw an exception? Good, but what if throwing an exception is not an option? 
*   You would then have to re-design the function (ie, add an extra parameter).
* 
*               
**********************************************************************************/

//12ms
class Solution1 {
public:
    int reverse(int x) {
        long res = 0;
		int sign = 1;
		if (x < 0) sign = -1, x = -x;
		string num = to_string(x);
		for (int i = num.size() - 1; i >= 0; i--) {
			res = res * 10 + (num.at(i) - '0');
		}
		res = (res > INT_MAX) ? 0 : res;
		return res * sign;
        
    }
};

//8ms
class Solution {
public:
    int reverse(int x) {
        long result = 0;
    while(x != 0)
    {
        result = result*10 + x % 10;
        x /= 10;
    }
    return (result > INT_MAX || result < INT_MIN)? 0 : result;
        
    }
};
