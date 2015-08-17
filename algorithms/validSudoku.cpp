// Source : https://leetcode.com/problems/valid-sudoku/
// Author : Siyuan Xu
// Date   : 2015-08-07

/********************************************************************************** 
* 
* Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
* 
* The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
* 
* A partially filled sudoku which is valid.
* 
* Note:
* > A valid Sudoku board (partially filled) is not necessarily solvable. 
*   Only the filled cells need to be validated.
* 
*               
**********************************************************************************/

//20ms(not best)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<int> checkSet[3][9];
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++){
				int k = (i / 3) * 3 + (j / 3);
				if (board[i][j] == '.') continue;
				int d = board[i][j] - '0';
				if (checkSet[0][i].find(d) != checkSet[0][i].end())
					return false;
				else checkSet[0][i].insert(d);
				if (checkSet[1][j].find(d) != checkSet[1][j].end())
					return false;
				else checkSet[1][j].insert(d);
				if (checkSet[2][k].find(d) != checkSet[2][k].end())
					return false;
				else checkSet[2][k].insert(d);
			}
		}
		return true;
    }
};
