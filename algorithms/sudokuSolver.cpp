// Source : https://leetcode.com/problems/sudoku-solver/
// Author : Siyuan Xu
// Date   : 2015-08-07

/********************************************************************************** 
* 
* Write a program to solve a Sudoku puzzle by filling the empty cells.
* 
* Empty cells are indicated by the character '.'.
* 
* You may assume that there will be only one unique solution.
* 
* A sudoku puzzle...
* 
* ...and its solution numbers marked in red.
* 
*               
**********************************************************************************/

//dfs
//220m slow
class Solution {
public:
    void dfs(vector<vector<char>>& board, set<int> checkSet[][9], int n, bool& solved) {
		if (n == 81) { 
			solved = true; 
			return; 
		}
		int i = n / 9, j = n % 9, k = (i / 3) * 3 + (j / 3);
		if (board[i][j] != '.') dfs(board, checkSet, n + 1, solved);
		else {
			for (int d = 1; d <= 9; d++) {
				if (!solved && checkSet[0][i].find(d) == checkSet[0][i].end() && checkSet[1][j].find(d) == checkSet[1][j].end() && checkSet[2][k].find(d) == checkSet[2][k].end()) {
					board[i][j] = '0' + d;
					checkSet[0][i].insert(d);
					checkSet[1][j].insert(d);
					checkSet[2][k].insert(d);
					dfs(board, checkSet, n + 1, solved);
					if (solved) return;
					else { 
						board[i][j] = '.'; 
						checkSet[0][i].erase(d);
						checkSet[1][j].erase(d);
						checkSet[2][k].erase(d);
					}
				}
			}
		}
	}
    void solveSudoku(vector<vector<char>>& board) {
        set<int> checkSet[3][9];
		bool solved = false;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				int k = (i / 3) * 3 + (j / 3);
				if (board[i][j] == '.') continue;
				int d = board[i][j] - '0';
				checkSet[0][i].insert(d);
				checkSet[1][j].insert(d);
				checkSet[2][k].insert(d);
			}
		}
		dfs(board, checkSet, 0, solved);
    }
};
