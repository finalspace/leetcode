// Source : https://leetcode.com/problems/trapping-rain-water/
// Author : Siyuan Xu
// Date   : 2015-08-10

/********************************************************************************** 
* 
* Given n non-negative integers representing an elevation map where the width of each bar is 1, 
* compute how much water it is able to trap after raining. 
* 
* For example, 
* Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*   
*     ^                                             
*     |                                             
*   3 |                       +--+                  
*     |                       |  |                  
*   2 |          +--+xxxxxxxxx|  +--+xx+--+         
*     |          |  |xxxxxxxxx|  |  |xx|  |         
*   1 |   +--+xxx|  +--+xxx+--+  |  +--+  +--+      
*     |   |  |xxx|  |  |xxx|  |  |  |  |  |  |      
*   0 +---+--+---+--+--+---+--+--+--+--+--+--+----->
*       0  1   0  2  1   0  1  3  2  1  2  1        
* 
* The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 
* 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*               
**********************************************************************************/

//smart solution
//8ms 
class Solution1 {
public:
    int trap(vector<int>& height) {
        //scan A both from left to right and right to left, record the largest seen during the scan; then for each position the water level should be the min of the 2 large value.
        int i, res = 0, n = height.size();
        if(!n) return res;
        vector<int> ltr(n, 0), rtl(n, 0);
        for(i = 1, ltr[0] = height[0]; i < n; i++)
            ltr[i] = max(ltr[i-1], height[i]);
        for(i = n - 2, rtl[n-1] = height[n-1]; i >= 0; i--)
            rtl[i] = max(rtl[i+1], height[i]);
        for(i = 0; i < n; i++)
            res += min(ltr[i], rtl[i]) - height[i];
        return res;
    }
};

//think about why should move the shorter bar
//8ms(best)
class Solution2 {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
		int res = 0;
		int l = 0;
		int r = height.size() -1;
		while(l<r){
			int lh = height[l];
			int rh = height[r];
			if (lh<=rh){
				while((l<=r)&&(height[l]<=lh)){
					res+=lh-height[l];
					l++;
				}
			}
			else{
				while((l<=r)&&(height[r]<=rh)){
					res+=rh-height[r];
					r--;
				}
			}
		}
		return res;
    }
};
