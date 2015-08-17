// Source : https://leetcode.com/problems/maximal-rectangle/
// Author : Siyuan Xu
// Date   : 2015-08-13

/********************************************************************************** 
* 
* Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle 
* containing all ones and return its area.
*               
**********************************************************************************/


//12ms(best)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
		int res;
		int m = matrix.size(), n = matrix[0].size();
		vector<int> height(n, 0), left(n, 0), right(n, n);
		for (int i = 0; i < m; i++) {
			int leftMost = 0, rightMost = n - 1;
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == '1') height[j]++;
				else height[j] = 0;
			}
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == '0') { leftMost = j + 1; left[j] = 0; }
				else { left[j] = max(left[j], leftMost); }
			}

			for (int j = n - 1; j >=0; j--) {
				if (matrix[i][j] == '0') { rightMost = j - 1; right[j] = n - 1; }
				else { right[j] = min(right[j], rightMost); }
			}

			for (int j = 0; j < n; j++) {
				res = max(res, height[j] * (right[j] - left[j] + 1));
			}
		}
		return res;
    }
};
