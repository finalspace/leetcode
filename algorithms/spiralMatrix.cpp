// Source : https://leetcode.com/problems/spiral-matrix/
// Author : Siyuan Xu
// Date   : 2015-08-12

/********************************************************************************** 
* 
* Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
* 
* For example,
* Given the following matrix:
* 
* [
*  [ 1, 2, 3 ],
*  [ 4, 5, 6 ],
*  [ 7, 8, 9 ]
* ]
* 
* You should return [1,2,3,6,9,8,7,4,5].
* 
*               
**********************************************************************************/


//0ms(best)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
		if (matrix.empty() || matrix[0].empty()) return res;
		int m = matrix.size(), n = matrix[0].size();
		int dirMap[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
		int k = 0;
		int board[4] = { -1, n, m, -1 };
		int boardShrink[4] = {1, -1, -1, 1};
		int x = 0, y = 0, newX = 0, newY = 0;
		while (board[3] < board[1] - 1 && board[0] < board[2] - 1) {
			res.push_back(matrix[x][y]);
			newX = x + dirMap[k][0]; newY = y + dirMap[k][1];
			if ((board[0] < newX) && (newX < board[2])
				&& (board[3] < newY) && (newY < board[1])) {
				x = newX; y = newY;
				continue;
			}
			board[k] += boardShrink[k];
			k = (k + 1) % 4;
			x = x + dirMap[k][0]; y = y + dirMap[k][1];
		}
		return res;
    }
};
