// Source : https://leetcode.com/problems/gray-code/
// Author : Siyuan Xu
// Date   : 2015-08-13

/********************************************************************************** 
* 
* The gray code is a binary numeral system where two successive values differ in only one bit.
* 
* Given a non-negative integer n representing the total number of bits in the code, 
* print the sequence of gray code. A gray code sequence must begin with 0.
* 
* For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
* 
* 00 - 0
* 01 - 1
* 11 - 3
* 10 - 2
* 
* Note:
* For a given n, a gray code sequence is not uniquely defined.
* 
* For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
* 
* For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*               
**********************************************************************************/

//deduction
//4ms(best)
class Solution1 {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
		res.push_back(0);
		for (int i = 1; i <= n; i++) {
			for (int k = res.size() - 1; k >= 0; k--) {
				res.push_back(res[k] | (1 << (i - 1)));
			}
		}
		return res;
    }
};

//formula
//4ms(best)
class Solution2 {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
		for (int i = 0; i < pow(2, n); i++)
			res.push_back(i ^ (i >> 1));
		return res;
    }
};


//dfs
//8ms(medium)
class Solution3 {
public:
    void dfs(vector<int> &res, vector<bool> &aval, int n, int code, int &sum, int target) {
		if (sum == target)
			return;
		for (int i = 0; i < n; i++) {
			if (aval[code ^ (1 << i)]) {
				code = code ^ (1 << i);
				aval[code] = false;
				res.push_back(code);
				dfs(res, aval, n, code, ++sum, target);
			}
		}
	}
    vector<int> grayCode(int n) {
        vector<int> res(1, 0);
		vector<bool> aval(pow(2, n), true);
		aval[0] = false;
		int sum = 0;
		dfs(res, aval, n, 0, sum, pow(2, n));
		return res;
    }
};
