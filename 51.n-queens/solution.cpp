class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		int *answer = new int[n];
		int **p = new int*[n];
		for (int i = 0; i < n; i++)
		{
			p[i] = new int[n];
			memset(p[i], 0, n * sizeof(int));
		}
		solveNQueens(result, answer, p, n, 0);
		for (int i = 0; i < n; i++)
			delete[] p[i];
		delete[] p;
		return result;
	}
private:
	void solveNQueens(vector<vector<string>> &result, int *answer, int **p, int n, int j)
	{
		if (j == n)
		{
			result.emplace_back(n, string(n, '.'));
			for (int i = 0; i < n; i++)
				result.back()[i][answer[i]] = 'Q';
			return;
		}
		for (int i = 0; i < n; i++)
		{
			if (!p[j][i])
			{
				answer[j] = i;
				for (int k = j + 1; k < n; k++)
				{
					p[k][i]++;
					int i1 = k - j + i;
					int i2 = j - k + i;
					if (i1 < n)
						p[k][i1]++;
					if (i2 >= 0)
						p[k][i2]++;
				}
				solveNQueens(result, answer, p, n, j + 1);
				for (int k = j + 1; k < n; k++)
				{
					p[k][i]--;
					int i1 = k - j + i;
					int i2 = j - k + i;
					if (i1 < n)
						p[k][i1]--;
					if (i2 >= 0)
						p[k][i2]--;
				}
			}
		}
	}
};
