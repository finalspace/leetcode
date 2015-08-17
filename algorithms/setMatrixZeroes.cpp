// Source : https://leetcode.com/problems/set-matrix-zeroes/
// Author : Siyuan Xu
// Date   : 2015-08-12

/********************************************************************************** 
* 
* Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
* 
* click to show follow up.
* 
* Follow up:
* 
* Did you use extra space?
* A straight forward solution using O(mn) space is probably a bad idea.
* A simple improvement uses O(m + n) space, but still not the best solution.
* Could you devise a constant space solution?
* 
*               
**********************************************************************************/

//in place
//88ms(good)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
		bool colZero = false;
		for (int i = 0; i < m; i++) {
			if (matrix[i][0] == 0) colZero = true;
			for (int j = 1; j < n; j++) {
				if (matrix[i][j] == 0)
					matrix[i][0] = matrix[0][j] = 0;
			}
		}
		for (int i = m - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 1; j--) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			}
			if (colZero) {
				matrix[i][0] = 0;
			}
		}
    }
};

//helper space
//84ms(best)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
		int m = matrix.size(), n = matrix[0].size();
		vector<bool> row(m, false);
		vector<bool> col(n, false);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 0)
					row[i] = col[j] = true;
			}
		}
		for (int i = 0; i < m; i++) {
			if (row[i]) {
				fill(matrix[i].begin(), matrix[i].end(), 0);
			}
		}
		for (int j = 0; j < n; j++) {
			if (col[j]) {
				for (int i = 0; i < m; i++) {
					matrix[i][j] = 0;
				}
			}
		}
    }
};
