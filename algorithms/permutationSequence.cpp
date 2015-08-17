// Source : https://leetcode.com/problems/permutation-sequence/
// Author : Siyuan
// Date   : 2015-08-10

/********************************************************************************** 
* 
* The set [1,2,3,…,n] contains a total of n! unique permutations.
* 
* By listing and labeling all of the permutations in order,
* We get the following sequence (ie, for n = 3):
* 
* "123"
* "132"
* "213"
* "231"
* "312"
* "321"
* 
* Given n and k, return the kth permutation sequence.
* 
* Note: Given n will be between 1 and 9 inclusive.
*               
**********************************************************************************/

//smart solution
//0ms(best)
class Solution {
public:
    int factorial(int n) {
		if (n <= 2) return n;
		return n * factorial(n - 1);
	}
    string getPermutation(int n, int k) {
        string res;
		vector<char> digits;
		for (int i = 1; i <= n; i++) {
			digits.push_back('0' + i);
		}
		int nFactorial = factorial(n - 1);
		k--;
		for (int i = 0; i < n - 1; i++) {
			int pos = k / nFactorial;
			res += digits[pos];
			digits.erase(digits.begin() + pos);
			k = k % nFactorial;
			nFactorial /= n - i - 1;
		}
		res += digits[0];
		return res;
    }
};
