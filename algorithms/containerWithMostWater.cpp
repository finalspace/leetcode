// Source : https://leetcode.com/problems/container-with-most-water/
// Author : Siyuan Xu
// Date   : 2015-06-02

/********************************************************************************** 
* 
* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
* n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
* 
* Find two lines, which together with x-axis forms a container, such that the container contains the most water.
* 
* Note: You may not slant the container.
* 
*               
**********************************************************************************/

//starting from two ends, always move the shortor bar
//28ms
class Solution1 {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int minH;
        int max = 0;
        while (i<j){
            minH = min(height[i], height[j]);
            int v = minH * (j-i);
            max = (v>max) ? v : max;
            while((i<j)&&(height[i]<=minH)){
              i++;
            }
            while((i<j)&&(height[j]<=minH)){
              j--;
            }
        }
        return max;
        
    }
};
