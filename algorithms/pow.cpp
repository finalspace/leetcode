// Source : https://leetcode.com/problems/powx-n/
// Author : Siyuan Xu
// Date   : 2015-08-11

/********************************************************************************** 
* 
* Implement pow(x, n).
* 
*               
**********************************************************************************/

//binary divide and conquer
//4ms(best)
class Solution {
public:
    double myPowPositive(double x, int n){
		if (n == 0) return 1;
		if (n == 1) return x;
		double t= myPow(x, n/2);
		if (n%2==1) return t * t * x;
		else return t * t;
	}
    double myPow(double x, int n) {
		if (n<0)
			return 1.0 / myPowPositive(x, -n);
		else return myPowPositive(x, n);
    }
};
