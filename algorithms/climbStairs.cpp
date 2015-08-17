// Source : https://leetcode.com/problems/climbing-stairs/
// Author : Siyuan Xu
// Date   : 2015-08-11

/********************************************************************************** 
* 
* You are climbing a stair case. It takes n steps to reach to the top.
* 
* Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
* 
*               
**********************************************************************************/

//0ms(best)
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
		if (n == 1) return 1;
		if (n == 2) return 2;
		int a = 1, b = 2;
		for (int i = 0; i < n - 2; i++) {
			int temp = a + b;
			a = b;
			b = temp;
		}
		return b;
    }
};
