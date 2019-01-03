class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		if (n > 0)
		{
			bool **curr = new bool *[n];
			for (int i = 0; i < n; i++)
			{
				curr[i] = new bool[n];
				memset(curr[i], false, n);
			}
			solveNQueens(result, curr, n, n, 0, 0);
			for (int i = 0; i < n; i++)
				delete[] curr[i];
			delete[] curr;
		}
		return result;
	}
private:
	void solveNQueens(vector<vector<string>> &result, bool **p, int max, int n, int curi, int curj)
	{
		int j = curj;
		for (int i = curi; i < max; i++)
		{
			for (; j < max; j++)
			{
				bool check = true;
				for (int k = 0; k < max; k++)
				{
					if (p[k][j] || p[i][k]
						|| (j - i + k >= 0 && j - i + k < max && p[k][j - i + k])
						|| (i + j - k >= 0 && i + j - k < max && p[k][i + j - k]))
					{
						check = false;
						break;
					}
				}
				if (check)
				{
					p[i][j] = true;
					if (n == 1)
					{
						result.emplace_back();
						for (int x = 0; x < max; x++)
						{
							string s;
							for (int y = 0; y < max; y++)
								s += p[x][y] ? 'Q' : '.';
							result.back().push_back(s);
						}
						p[i][j] = false;
						return;
					} else
					{
						solveNQueens(result, p, max, n - 1, i, j);
						p[i][j] = false;
					}
				}
			}
			j = 0;
		}
	}
};
