class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (word.empty()) return false;
		int m = board.size();
		if (m == 0) return false;
		int n = board.front().size();
		set<pair<int, int>> cache;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == word.front())
				{
					pair<int, int> p(i, j);
					cache.insert(p);
					if (exist(board, word, cache, i, j)) return true;
					cache.erase(p);
				}
			}
		}
		return false;
	}
private:
	bool exist(vector<vector<char>>& board, const string &word, set<pair<int, int>> &cache, int x, int y) {
		int len = cache.size();
		if (len == word.length()) return true;
		if (x > 0 && word[len] == board[x - 1][y])
		{
			pair<int, int> p(x - 1, y);
			if (cache.insert(p).second)
			{
				if (exist(board, word, cache, x - 1, y)) return true;
				cache.erase(p);
			}
		}
		if (y > 0 && word[len] == board[x][y - 1])
		{
			pair<int, int> p(x, y - 1);
			if (cache.insert(p).second)
			{
				if (exist(board, word, cache, x, y - 1)) return true;
				cache.erase(p);
			}
		}
		if (x < board.size() - 1 && word[len] == board[x + 1][y])
		{
			pair<int, int> p(x + 1, y);
			if (cache.insert(p).second)
			{
				if (exist(board, word, cache, x + 1, y)) return true;
				cache.erase(p);
			}
		}
		if (y < board.front().size() - 1 && word[len] == board[x][y + 1])
		{
			pair<int, int> p(x, y + 1);
			if (cache.insert(p).second)
			{
				if (exist(board, word, cache, x, y + 1)) return true;
				cache.erase(p);
			}
		}
		return false;
	}
};
