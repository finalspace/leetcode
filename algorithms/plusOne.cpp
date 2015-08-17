// Source : https://leetcode.com/problems/plus-one/
// Author : Siyuan Xu
// Date   : 2015-08-11

/********************************************************************************** 
* 
* Given a non-negative number represented as an array of digits, plus one to the number.
* 
* The digits are stored such that the most significant digit is at the head of the list.
*               
**********************************************************************************/


//concise solution
//4ms(best)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
		for (int i = n - 1; i >= 0; --i)
		{
			if (digits[i] == 9) digits[i] = 0;
			else{
				digits[i]++;
				return digits;
			}
		}
		digits[0] = 1;
		digits.push_back(0);
		return digits;
    }
};

//staightforward solution
//4ms(best)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
		int k = digits.size() - 2;
		carry = (digits[digits.size() - 1] + 1) / 10;
		digits[digits.size() - 1] = (digits[digits.size() - 1] + 1) % 10;
		while (carry && k >= 0){
			digits[k] = digits[k] + carry;
			carry = digits[k] / 10;
			digits[k] = digits[k] % 10;
			k--;
		}
		if (carry) {
			digits.insert(digits.begin(), 1);
		}
		return digits;
    }
};
