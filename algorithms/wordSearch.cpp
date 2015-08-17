// Source : https://leetcode.com/problems/word-search/
// Author : Siyuan Xu
// Date   : 2015-08-12

/********************************************************************************** 
* 
* Given a 2D board and a word, find if the word exists in the grid.
* 
* The word can be constructed from letters of sequentially adjacent cell, 
* where "adjacent" cells are those horizontally or vertically neighboring. 
* The same letter cell may not be used more than once.
* 
* For example,
* Given board = 
* 
* [
*   ["ABCE"],
*   ["SFCS"],
*   ["ADEE"]
* ]
* 
* word = "ABCCED", -> returns true,
* word = "SEE", -> returns true,
* word = "ABCB", -> returns false.
* 
*               
**********************************************************************************/

//40ms(medium)
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& aval, int x, int y, int k) {
		if (k >= word.size()) { return true; }
		int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
		bool found = false;
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (xx >= 0 && xx < board.size() && yy >= 0 && yy < board[0].size() && aval[xx][yy] && board[xx][yy] == word[k]) {
				aval[xx][yy] = false;
				found = dfs(board, word, aval, xx, yy, k + 1);
				if (found) return true;
				aval[xx][yy] = true;
			}
		}
		return found;
	}
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) {
			return word.empty() ? true : false;
		}
		int m = board.size(), n = board[0].size();
		vector<vector<bool>> aval(m, vector<bool>(n, true));
		int dir[4][2] = { -1, 0, 0, 1, 1, 0, 0, -1 };
		bool found = false;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == word[0]) {
					aval[i][j] = false;
					found = dfs(board, word, aval, i, j, 1);
					if (found) return true;
					aval[i][j] = true;
				}
			}
		}
		return false;
    }
};
