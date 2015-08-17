// Source : https://leetcode.com/problems/rotate-image/
// Author : Siyuan Xu
// Date   : 2015-08-11

/********************************************************************************** 
* 
* You are given an n x n 2D matrix representing an image.
* Rotate the image by 90 degrees (clockwise).
* Follow up:
* Could you do this in-place?
*               
**********************************************************************************/

//4ms(best)
class Solution1 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
		for(int i = 0; i <= (n-1)/2; i++){
			for(int j = i; j < n - i -1; j++){
				int m = matrix[i][j];
				matrix[i][j] = matrix[n-1-j][i];
				matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
				matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
				matrix[j][n-1-i] = m;
			}
		}
    }
};
