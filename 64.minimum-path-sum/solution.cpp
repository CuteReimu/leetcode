class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int h = grid.size();
		int w = grid.front().size();
		vector<vector<int>> vec = grid;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				int a = INT_MAX, b = INT_MAX;
				if (j > 0) a = vec[i][j - 1];
				if (i > 0) b = vec[i - 1][j];
				if (i > 0 || j > 0)
					vec[i][j] += a < b ? a : b;
			}
		}
		return vec[h - 1][w - 1];
	}
};
