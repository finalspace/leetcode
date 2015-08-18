// Source : https://leetcode.com/problems/spiral-matrix-ii/
// Author : Siyuan Xu
// Date   : 2015-08-08

/********************************************************************************** 
* 
* Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
* 
* For example,
* Given n = 3,
* 
* You should return the following matrix:
* 
* [
*  [ 1, 2, 3 ],
*  [ 8, 9, 4 ],
*  [ 7, 6, 5 ]
* ]
* 
*               
**********************************************************************************/

//easy to understand solution
//4ms(best)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
		int rowStart = 0, rowEnd = n - 1;
		int colStart = 0, colEnd = n - 1;
		int k = 1;
		while (rowStart <= rowEnd && colStart <= colEnd) {
			for (int i = colStart; i <= colEnd; i++)
				res[rowStart][i] = k++;
			rowStart++;
			for (int i = rowStart; i <= rowEnd; i++)
				res[i][colEnd] = k++;
			colEnd--;
			for (int i = colEnd; i >= colStart; i--)
				res[rowEnd][i] = k++;
			rowEnd--;
			for (int i = rowEnd; i >= rowStart; i--)
				res[i][colStart] = k++;
			colStart++;;
		}
		return res;
    }
};


//my old classic way to solve this type of problem
//4ms(best)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
		for (int i = 0; i < n; i++) {
			res.push_back(vector<int>(n, 0));
		}
		int dirMap[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };
		int k = 0;
		int board[4] = { -1, n, n, -1 };
		int boardShrink[4] = { 1, -1, -1, 1 };
		int x = 0, y = 0, newX = 0, newY = 0;
		int d = 1;
		while (board[3] < board[1] - 1 && board[0] < board[2] - 1) {
			res[x][y] = d++;
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
