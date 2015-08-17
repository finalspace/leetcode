// Source : https://leetcode.com/problems/add-binary/
// Author : Siyuan Xu
// Date   : 2015-08-11

/********************************************************************************** 
* 
* Given two binary strings, return their sum (also a binary string).
* 
* For example,
* a = "11"
* b = "1"
* Return "100".
* 
*               
**********************************************************************************/

//concise
//4ms
class Solution1 {
public:
    string addBinary(string a, string b) {
        string res = "";
		int i = a.size() - 1, j = b.size() - 1;
		int c = 0;
		while (i >= 0 || j >= 0 || c > 0) {
			c += (i >= 0) ? a[i--] - '0' : 0;
			c += (j >= 0) ? b[j--] - '0' : 0;
			res = char('0' + c % 2) + res;
			c = c / 2;
		}
		return res;
    }
};

//4ms(best)
class Solution2 {
public:
    string addBinary(string a, string b) {
        string res(max(a.size(), b.size()), ' ');
		if (a.size() < b.size()) swap(a, b);
		int carry = 0;
		int pa = a.size() - 1, pb = b.size() - 1;
		while (pa >= 0) {
			int temp = (a[pa] - '0') + carry;
			temp += (pb >= 0) ? (b[pb] - '0') : 0;
			carry = temp / 2;
			res[pa] = '0' + (temp % 2);
			pa--; pb--;
			
		}
		if (carry) res.insert(res.begin(), '1');
		return res;
    }
};
