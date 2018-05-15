class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++)
		{
			set<char> cacher;
			set<char> cachel;
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] != '.' && !cacher.insert(board[i][j]).second)
					return false;
				if (board[j][i] != '.' && !cachel.insert(board[j][i]).second)
					return false;
			}
		}
		return checkSquare(board, 0, 0) && checkSquare(board, 3, 0) && checkSquare(board, 6, 0)
			&& checkSquare(board, 0, 3) && checkSquare(board, 3, 3) && checkSquare(board, 6, 3)
			&& checkSquare(board, 0, 6) && checkSquare(board, 3, 6) && checkSquare(board, 6, 6);
	}
private:
	bool checkSquare(vector<vector<char>>& board, int lbase, int rbase)
	{
		set<char> cache;
		if (board[lbase][rbase] != '.' && !cache.insert(board[lbase][rbase]).second) return false;
		if (board[lbase + 1][rbase] != '.' && !cache.insert(board[lbase + 1][rbase]).second) return false;
		if (board[lbase + 2][rbase] != '.' && !cache.insert(board[lbase + 2][rbase]).second) return false;
		if (board[lbase][rbase + 1] != '.' && !cache.insert(board[lbase][rbase + 1]).second) return false;
		if (board[lbase + 1][rbase + 1] != '.' && !cache.insert(board[lbase + 1][rbase + 1]).second) return false;
		if (board[lbase + 2][rbase + 1] != '.' && !cache.insert(board[lbase + 2][rbase + 1]).second) return false;
		if (board[lbase][rbase + 2] != '.' && !cache.insert(board[lbase][rbase + 2]).second) return false;
		if (board[lbase + 1][rbase + 2] != '.' && !cache.insert(board[lbase + 1][rbase + 2]).second) return false;
		if (board[lbase + 2][rbase + 2] != '.' && !cache.insert(board[lbase + 2][rbase + 2]).second) return false;
		return true;
	}
};
