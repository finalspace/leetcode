// Source : https://leetcode.com/problems/implement-strstr/
// Author : Siyuan Xu
// Date   : 2015-08-04

/********************************************************************************** 
* 
* Implement strStr().
* 
* Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
* 
*               
**********************************************************************************/

//4ms(best)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int res = -1;
		int l = needle.size();
		for(int i = 0; i<= ((int)haystack.size() - (int)needle.size());i ++){
			if (haystack.substr(i,l) == needle){
				return i;
			}
		}
        return res;
    }
};
