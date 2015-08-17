// Source : https://leetcode.com/problems/multiply-strings/
// Author : Siyuan
// Date   : 2015-08-10

/********************************************************************************** 
* 
* Given two numbers represented as strings, return multiplication of the numbers as a string.
* 
* Note: The numbers can be arbitrarily large and are non-negative.
*               
**********************************************************************************/

//8ms(good)
class Solution {
public:
    string multiply(string num1, string num2) {
        string sum(num1.size() + num2.size(), '0');
		for(int i = num2.size() - 1; i>=0; i--){
			int carry = 0;
			for(int j = num1.size() - 1; j >=0; j--){
				int m = (num1[j] - '0') * (num2[i] - '0') + (sum[i+j+1] - '0') + carry;
				sum[i+j+1] = '0' + m % 10;
				carry = m / 10;
			}
			sum[i] = '0' + carry;
		}
		auto it = sum.find_first_not_of('0');
		return (it==string::npos) ? "0" : sum.substr(it);
    }
};
