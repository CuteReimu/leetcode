class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid[0][0]) return 0;
		int h = obstacleGrid.size();
		int w = obstacleGrid.front().size();
		vector<vector<int>> vec(h, vector<int>(w, 0));
		vec[0][0] = 1;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (!obstacleGrid[i][j])
				{
					if (j > 0) vec[i][j] += vec[i][j - 1];
					if (i > 0) vec[i][j] += vec[i - 1][j];
				}
			}
		}
		return vec[h - 1][w - 1];
	}
};
