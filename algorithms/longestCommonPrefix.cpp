// Source : https://leetcode.com/problems/longest-common-prefix/
// Author : Siyuan Xu
// Date   : 2015-08-03

/********************************************************************************** 
* 
* Write a function to find the longest common prefix string amongst an array of strings.
* 
*               
**********************************************************************************/

//8ms
class Solution1 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        string res = "";
        int k = 0;
        while(1){
            for(int i = 1; i<=strs.size()-1;i++){
                if ((k>=strs[i].size()) || (strs[i][k] != strs[i-1][k]))
                    return res;
            }
            res.push_back(strs[0][k++]);
        }
        return res;
    }
};
