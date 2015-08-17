// Source : https://leetcode.com/problems/divide-two-integers/
// Author : Siyuan
// Date   : 2015-08-04

/********************************************************************************** 
* 
* Divide two integers without using multiplication, division and mod operator.
* 
* If it is overflow, return MAX_INT. 
*
**********************************************************************************/

//bitwise operation
//8ms(best)
class Solution1 {
public:
    typedef long long ll;
    int divide(int dividend, int divisor) {
        if (divisor ==0) return INT_MAX;
		if (dividend ==0) return 0;
		if ((dividend == INT_MIN) && (divisor == -1)) return INT_MAX;
		ll res=0;
		int sign = ((dividend>0)&&(divisor>0)) || ((dividend<0)&&(divisor<0)) ? 1 : -1;
		ll dd = abs((ll)dividend);
		ll dr = abs((ll)divisor);
		//if (dr == 1) return dd * sign;
		while(dd>=dr){
			ll a = dr;
			int m = 1;
			while(a<<1<dd){
				a=a<<1; m=m<<1;
			}
			res+=m;
			dd-=a;
		}
	
	
//cheat(using exponent operation)
//12ms
class Solution2 {
public:
    int divide(int dividend, int divisor) {
        if (dividend==0) return 0;
        if (divisor==0) return INT_MAX;
        long long res=double(exp(log(fabs(dividend))-log(fabs(divisor))));
        if ((dividend<0)^(divisor<0)) res=-res;
        if (res>INT_MAX) res=INT_MAX;
        return res;
    }
};

//bitwise operation
//8ms(best)
class Solution2 {
public:
    typedef long long ll;
    int divide(int dividend, int divisor) {
        if(divisor == 1)
        return dividend;
    if(dividend == INT_MIN && abs(divisor) == 1)
        return INT_MAX;
    /*********************************************/

    int sign = (dividend > 0 ^ divisor > 0) ? -1 : 1;

    long ans = 0;
    long end = abs((long)dividend);
    long sor = abs((long)divisor);

    while(end >= sor) {
        long temp  = sor;
        long power = 1;
        while((temp << 1) < end) {
            power <<= 1;
            temp  <<= 1;
        }
        ans += power;
        end -= temp;
    }
    return sign * ans;
    }
};
