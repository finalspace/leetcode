// Source : https://leetcode.com/problems/sqrtx/
// Author : Siyuan Xu
// Date   : 2015-08-11

/********************************************************************************** 
* 
* Implement int sqrt(int x).
* 
* Compute and return the square root of x.
*               
**********************************************************************************/

//8ms(best)
class Solution1 {
public:
    int mySqrt(int x) {
        int ans = 0;
		long long bit = 1 << 15;
		while (bit > 0) {
			ans |= bit;
			if (x / ans < ans) {
				ans ^= bit;
			}
			bit >>= 1;
		}
		return int(ans);
    }
};

//8ms(best)
class Solution2 {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
		int l = 1, r = x;
		while (l < r - 1) {
			int mid = (l + r) / 2, temp = x / mid;
			if (temp == mid) return mid;
			else if (temp > mid) l = mid;
			else r = mid;
		}
		return l;
    }
};

//8ms(best)
class Solution3 {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
		int l = 1, r = x;
		while (l < r - 1) {
			int mid = l + (r - l) / 2, temp = x / mid;
			if (temp == mid) return mid;
			else if (temp > mid) l = mid;
			else r = mid;
		}
		return l;
    }
};
