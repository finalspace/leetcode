// Source : https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
// Author : Hao Chen
// Date   : 2014-07-20

/********************************************************************************** 
 * 
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
 * find the area of largest rectangle in the histogram.
 * 
 *                    6          
 *                  +---+        
 *               5  |   |        
 *              +---+   |        
 *              |   |   |        
 *              |   |   |        
 *              |   |   |     3  
 *              |   |   |   +---+
 *        2     |   |   | 2 |   |
 *      +---+   |   |   +---+   |
 *      |   | 1 |   |   |   |   |
 *      |   +---+   |   |   |   |
 *      |   |   |   |   |   |   |
 *      +---+---+---+---+---+---+
 *      
 * Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 *      
 *      
 *                    6          
 *                  +---+        
 *               5  |   |        
 *              +-------|        
 *              |-------|        
 *              |-------|        
 *              |-------|     3  
 *              |-------|   +---+
 *        2     |-------| 2 |   |
 *      +---+   |-------|---+   |
 *      |   | 1 |-------|   |   |
 *      |   +---|-------|   |   |
 *      |   |   |-------|   |   |
 *      +---+---+---+---+---+---+
 *      
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10 unit.
 * 
 * For example,
 * Given height = [2,1,5,6,2,3],
 * return 10.
 * 
 *               
 **********************************************************************************/
 
 
//24ms(best)
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int res = 0;
		stack<int> stk;
		height.push_back(0);
		for(int i = 0; i < height.size(); i++){
			if (stk.empty() || height[i] >= height[stk.top()])
				stk.push(i);
			else{
				int tmp = stk.top();
				stk.pop();
				int newMax = (stk.empty()) ? height[tmp] * i : height[tmp] * (i - stk.top() - 1);
				res = max(res, newMax);
				i--;
			}
		}
		return res;
    }
};
 
//28ms(medium)
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> s;
		height.push_back(0);
		int result = 0;
		for (int i = 0; i < height.size(); ) {
			if (s.empty() || height[i] > height[s.top()])
				s.push(i++);
			else {
				int tmp = s.top();
				s.pop();
				result = max(result,
					height[tmp] * (s.empty() ? i : i - s.top() - 1));
			}
		}
		return result;
    }
};
 
