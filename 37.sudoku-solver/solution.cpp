class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		solveSudoku(board, 0);
	}
private:
	bool solveSudoku(vector<vector<char>>& board, int i) {
		int row, col;
		toNextNum(board, i, row, col);
		if (i >= 81)
			return true;
		for (int j = 1; j <= 9; j++)
		{
			board[row][col] = j + '0';
			if (!checkSodoku(board, row, col))
				continue;
			if (solveSudoku(board, i + 1))
				return true;
		}
		board[row][col] = '.';
		return false;
	}
	void toNextNum(const vector<vector<char>>& board, int &i, int &row, int &col)
	{
		if (i >= 81)
			return;
		row = i / 9;
		col = i % 9;
		while (board[row][col] != '.')
		{
			if (++i >= 81)
				return;
			row = i / 9;
			col = i % 9;
		}
	}
	bool checkSodoku(vector<vector<char>>& board, int row, int col)
	{
		set<char> cache;
		for (int i = 0; i < 9; i++)
		{
			char val = board[row][i];
			if (val == '.')
				continue;
			if (!cache.insert(val).second)
				return false;
		}
		cache.clear();
		for (int i = 0; i < 9; i++)
		{
			char val = board[i][col];
			if (val == '.')
				continue;
			if (!cache.insert(val).second)
				return false;
		}
		cache.clear();
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				char val = board[row / 3 * 3 + i][col / 3 * 3 + j];
				if (val == '.')
					continue;
				if (!cache.insert(val).second)
					return false;
			}
		}
		return true;
	}
};
