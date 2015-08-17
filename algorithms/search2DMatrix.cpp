// Source : https://leetcode.com/problems/search-a-2d-matrix/
// Author : Siyuan Xu
// Date   : 2015-08-12

/********************************************************************************** 
* 
* Write an efficient algorithm that searches for a value in an m x n matrix. 
* This matrix has the following properties:
* 
* Integers in each row are sorted from left to right.
* The first integer of each row is greater than the last integer of the previous row.
* 
* For example,
* 
* Consider the following matrix:
* 
* [
*   [1,   3,  5,  7],
*   [10, 11, 16, 20],
*   [23, 30, 34, 50]
* ]
* 
* Given target = 3, return true.
*               
**********************************************************************************/

//concise
//12ms(best)
class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
		int m = matrix.size(), n = matrix[0].size();
		int l = 0, r = m * n - 1;
		while(l <= r){
			int mid = (l + r) / 2, tmp = matrix[mid/n][mid%n];
			if (tmp == target) return true;
			if (target < tmp) r = mid - 1;
			else l = mid + 1;
		}
		return false;
    }
};

//normal binary search
//12ms(best)
class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
		int m = matrix.size(), n = matrix[0].size();
		int rowL = 0, colL = 0, rowR = m - 1, colR = n - 1;
		while (rowL < rowR || (rowL == rowR && colL <= colR)) {
			int diff = (rowR - rowL) * n + colR - colL;
			int midRow = (rowL * n + colL + diff / 2) / n, midCol = (rowL * n + colL + diff / 2) % n;
			int tmp = matrix[midRow][midCol];
			if (tmp == target) return true;
			if (tmp > target) {
				midCol--;
				if (midCol < 0) { midRow--; midCol = n - 1;}
				rowR = midRow; colR = midCol;
			}
			else { 
				midCol++;
				if (midCol >= n) { midRow++; midCol = 0; }
				rowL = midRow; colL = midCol; 
			}
		}
		return false;
    }
};
