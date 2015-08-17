// Source : https://oj.leetcode.com/problems/count-and-say/
// Author : Siyuan Xu
// Date   : 2015-08-08

/********************************************************************************** 
* 
* The count-and-say sequence is the sequence of integers beginning as follows:
* 1, 11, 21, 1211, 111221, ...
* 
* 1 is read off as "one 1" or 11.
* 11 is read off as "two 1s" or 21.
* 21 is read off as "one 2, then one 1" or 1211.
* 
* Given an integer n, generate the nth sequence.
* 
* Note: The sequence of integers will be represented as a string.
* 
*               
**********************************************************************************/

//reading: how to proof the count is always less then 10 (actually 5)
//https://leetcode.com/discuss/6762/how-to-proof-the-count-is-always-less-than-10

//0ms(best)
class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
		string pre = "1";
		string cur = "";
		while (n-- > 1) {
			int k = 1;
			char c = pre[0];
			int count = 1;
			while (k < pre.size()) {
				if (pre[k] == pre[k - 1]) {
					count++; k++; continue;
				}
				cur += '0' + count;
				cur += c;
				c = pre[k]; count = 1; k++;
			}
			cur += '0' + count;
			cur += c;
			pre = cur;
			cur = "";
		}
		return pre;
    }
};
